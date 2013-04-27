// jacobi method
#ifndef JACOBI_H
#define JACOBI_H

#include <iostream>
#include <cmath>
#include <fstream>
#include <omp.h>
#include "utils.h"

using namespace std;

void jacobi( cdouble tol, const int max_iteration,
			 const unsigned int n_dof,
			 double* u_new,
			 double* u_old,
			 double** M,
			 double* F,
			 double& E,
			 double* R);

double convergence_check ( double** M,
						   double* U,
						   double* F,
						   double* R,
						   const int n_dof);

double* v_cycle( cuint n_dof, cuint I, cuint J, cuint K,
			  cdouble dx2i, cdouble dy2i, cdouble dz2i,
			  cdouble tol, cuint max_iteration,
			  cdouble width, cdouble length, cdouble height,
			  cuint level, cuint max_level, double* F);

// 3D full weight restriction
void restriction( double* R, double* R_new, cuint I, cuint J, cuint K);


void coarse_map( double* R, double* R_new,
				 unsigned int nei[][3][3],
				 cuint i, cuint j, cuint k, cuint t_new );


#endif //JACOBI_H