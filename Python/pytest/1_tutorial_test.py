# 1_tutorial_test.py
"""Test Tutorial."""


import pathlib
import sys
import pytest

# Test case 1: test a simple function


def successful_increment(x):
    """
    This function increase argument x by 1
    """
    return x + 1


def test_case_1():
    """
    Test successful_increment()
    pytest discovers test prefixed test functions or methods outside of class
    """
    # Arrange
    OPERAND = 3
    EXPECTATION = OPERAND + 1

    # Act
    RESULT = successful_increment(OPERAND)

    # Assert
    assert RESULT == EXPECTATION


# Test case 2: test an exception

def successful_raise_exception():
    """
    This function raise an exception
    """
    raise SystemExit(1)


def test_case_2():
    """
    Test successful_raise_exception()
    """
    with pytest.raises(SystemExit):
        successful_raise_exception()

# Test case 3: test multiple methods of a class


class TestClass:
    """
    Test class
    Prefix your class with Test otherwise the class will be skipped by pytest

    Grouping tests in classes can be beneficial for the following reasons:
    - Test organization
    - Sharing fixtures for tests only in that particular class
    - Applying marks at the class level and having them implicitly apply to all tests

    Each test has a unique instance of the class when grouping tests inside classes
    Having each test share the same class instance would be very detrimental to test isolation and would promote poor test practices
    """

    value = 0

    def test_one(self):
        """
        Test string values
        """
        X = "this"
        assert "h" in X

    def test_two(self):
        """
        Test class attributes
        """
        X = self.value
        assert X == self.value

    def test_three(self):
        """
        Test floating-point values
        """
        EXPECTATION = 0.3
        assert (0.1 + 0.2) == pytest.approx(EXPECTATION)

# Test case 4: request a unique temporary directory for functional tests


def test_case_4(tmp_path: pathlib.Path):
    """
    Test a unique temporary directory
    List the name tmp_path in the test function signature,
    and pytest will lookup and call a fixture factory to create the resource before performing the test function call

    Find out what kind of builtin pytest --fixtures exist with the command:
    $ pytest --fixtures
    """
    # Arrange
    print(tmp_path, file=sys.stderr)  # tmp_path is a pathlib.Path object
    print(sys.path, file=sys.stderr)
    CONTENT = "content"

    # Act
    d = tmp_path / "sub"
    d.mkdir()
    p = d / "hello.txt"
    p.write_text(CONTENT, encoding="utf-8")

    # Assert
    assert p.read_text(encoding="utf-8") == CONTENT  # Test content
    assert len(list(tmp_path.iterdir())) == 1  # Test the number of created files

    assert True, "True to pass, False to look at values"

# Test case 5: match exception messages


def successful_raise_string_exception():
    """
    This function raise an exception with string
    """
    raise ValueError("Exception 123 raised")


def test_case_5():
    """
    Test matching exception messages
    Pass a match keyword parameter to the context-manager to test that a regular expression matches on the string representation of an exception
    """
    with pytest.raises(ValueError, match=r".* 123 .*"):
        successful_raise_string_exception()

# Test case 6: parametrize test


@pytest.mark.parametrize(
    # Test parameters (parametrize decorators)
    ["a", "b", "result"],
    [
        [1, 2, 5],
        [2, 3, 9],
        [5, 3, 18],
    ],
)
def test_case_6(a, b, result):
    """
    Test parameters
    """
    assert (a * b + 3) == result

# Test case 7: parametrize test with combinations


@pytest.mark.parametrize("x", [0, 1])
@pytest.mark.parametrize("y", [2, 3])
def test_case_7(x, y):
    """
    Test parameter combinations
    """
    print(f'x: {x}, y: {y}')
    pass

# Test case 8: parametrize test in a module


@pytest.mark.parametrize("n, expected", [(1, 2), (3, 4)])
class TestParametrizeClass:
    """
    Test parameters in a module
    """

    def test_simple_case(self, n, expected):
        assert n + 1 == expected

# Test case 9: request fixtures


@pytest.fixture(scope="function")
def get_list():
    """
    Fixtures are created when first requested by a test, and are destroyed based on their scope:
    - function: the default scope, the fixture is destroyed at the end of the test.
    - class: the fixture is destroyed during teardown of the last test in the class.
    - module: the fixture is destroyed during teardown of the last test in the module.
    - package: the fixture is destroyed during teardown of the last test in the package where the fixture is defined,
    including sub-packages and sub-directories within it.
    - session: the fixture is destroyed at the end of the test session (i.e., all tests requesting it).
    """
    return ["fixture1", "fixture2"]


def test_case_9(get_list: list):
    """
    Test requesting fixtures

    When pytest goes to run a test, it looks at the parameters in that test function's signature,
    and then searches for fixtures that have the same names as those parameters.
    Once pytest finds them, it runs those fixtures, captures what they returned (if anything),
    and passes those objects into the test function as arguments.
    """
    # Arrange
    SIZE = len(get_list)
    NAME = "fixture3"

    # Act
    get_list.append(NAME)

    # Assert
    assert get_list[-1] == NAME
    assert len(get_list) == SIZE + 1

# Test case 10: reuse fixtures


def test_case_10(get_list: list):
    """
    Test reusing fixtures (recommended for integration tests)

    Define a generic setup step that can be reused over and over,
    just like a normal function would be used.
    Two different tests can request the same fixture and have pytest give each test their own result from that fixture.
    """
    # Arrange
    BASE_NAME = "fixture"
    LENGTH = len(BASE_NAME)

    # Act
    LIST = get_list

    # Assert
    assert all((item[0:LENGTH] == BASE_NAME) for item in LIST)
    assert len(LIST) == 2

# Test case 11: teardown/cleanup


class FixtureClass:
    """
    A test fixture which has name and value
    """

    def __init__(self, name):
        self.name = name
        self.value = False

    def set(self):
        self.value = True


@pytest.fixture(scope="function")
def get_managed_list():
    """
    Use yield instead of return to add teardown/cleanup code to a fixture.
    The code before the yield runs as setup before the test;
    the code after the yield runs as teardown after the test finishes,
    regardless of the test's outcome (pass, fail, or error).
    """
    # Setup
    resource = [FixtureClass("fixture1")]
    yield resource

    # Teardown
    resource.clear()


def test_case_11(get_managed_list: list):
    """
    Test fixture teardown/cleanup

    A fixture defines its teardown by using yield in place of return.
    pytest runs the setup up to the yield, passes the yielded value into
    the test, then runs the remaining teardown code once the test completes.
    """
    # Arrange
    SIZE = len(get_managed_list)
    NAME = "fixture2"

    # Act
    get_managed_list.append(FixtureClass(NAME))

    # Assert
    assert get_managed_list[-1].name == NAME
    assert len(get_managed_list) == SIZE + 1

# Test case 12: parametrizing fixtures


@pytest.fixture(scope="function", params=["fixture1", "fixture2"])
def get_parametrized_list(request):
    """
    Fixtures can be parametrized in which case they will be called multiple times,
    each time executing the set of dependent tests, i.e. the tests that depend on this fixture.
    """
    return [request.param]


def test_case_12(get_parametrized_list: list):
    """
    Test parametrizing fixtures
    """
    # Arrange
    LIST = get_parametrized_list

    # Act
    SIZE = len(LIST)

    # Assert
    print(f'LIST: {LIST}')
    assert SIZE == 1
