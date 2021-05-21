cc=nvcc
NVCC_OPTIONS=-lcublas -lcudart -O3 -gencode=arch=compute_61,code=compute_61
OPENBLAS_INSTALL_PATH=~/github/OpenBLAS/build/
ALL:
	${cc} 1.cu -o gemm_test1 ${NVCC_OPTIONS} -I ${OPENBLAS_INSTALL_PATH} ${OPENBLAS_INSTALL_PATH}lib/libopenblas.a 
