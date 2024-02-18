cpdef list mul(a, b):
    cdef int rows_a = len(a)
    cdef int cols_a = len(a[0])
    cdef int rows_b = len(b)
    cdef int cols_b = len(b[0])

    if cols_a != rows_b:
        raise ValueError("Количество столбцов первой матрицы не равно количеству строк второй матрицы")

    cdef list result = [[0 for _ in range(cols_b)] for _ in range(rows_a)]

    for i in range(rows_a):
        for j in range(cols_b):
            for k in range(cols_a):
                result[i][j] += a[i][k] * b[k][j]

    return result
