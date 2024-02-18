import timeit
from matrix import mul


# Функция умножения матриц на чистом Python
def python_version(a, b):
    rows_a = len(a)
    cols_a = len(a[0])
    rows_b = len(b)
    cols_b = len(b[0])

    if cols_a != rows_b:
        raise ValueError("Количество столбцов первой матрицы не равно количеству строк второй матрицы")

    result = [[0 for _ in range(cols_b)] for _ in range(rows_a)]

    for i in range(rows_a):
        for j in range(cols_b):
            for k in range(cols_a):
                result[i][j] += a[i][k] * b[k][j]

    return result


matrix_one = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9],
    [10, 11, 12],
]

matrix_two = [
    [1, 2],
    [1, 2],
    [3, 4],
]


def test():
    cython_time = timeit.timeit(
        lambda: mul(matrix_one, matrix_two), number=100)
    python_time = timeit.timeit(
        lambda: python_version(matrix_one, matrix_two), number=100)

    print(f"Cython time = {cython_time}\nPython time = {python_time}")


if __name__ == "__main__":
    test()
