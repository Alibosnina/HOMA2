#include "C_DGLSolver.h" 
#include "CMyVektor.h" 
#include <iostream> 


C_DGLSolver::C_DGLSolver(CMyVektor(*f_DGL_System)(CMyVektor y, double x)) {
    this->hohereOrdnung = false; // Set flag to indicate first-order system
    this->f_DGL_System = f_DGL_System; // Assign function pointer to the differential equation system
}


C_DGLSolver::C_DGLSolver(double (*f_DGL_nterOrdnung)(CMyVektor y, double x)) {
    this->hohereOrdnung = true; // Set flag to indicate higher-order system
    this->f_DGL_nterOrdnung = f_DGL_nterOrdnung; // Assign function pointer to the nth order differential equation
}


CMyVektor C_DGLSolver::ableitungen(CMyVektor y, double x) {
    CMyVektor result; // Declare result vector
    result.makeVektor(y.getDimension()); // Initialize result vector with the same dimension as y

    if (!this->hohereOrdnung) { // If it's a first-order system
        result = f_DGL_System(y, x); // Compute derivatives using the system function
        return result; // Return the result vector
    } else { // If it's a higher-order system
        for (int i = 0; i < y.getDimension() - 1; i++) {
            result.setComponent(i, y.getComponent(i + 1)); // Shift components for higher-order derivative computation
        }
        result.setComponent(y.getDimension() - 1, f_DGL_nterOrdnung(y, x)); // Compute last component using the nth order function
        return result; 
    }
}


void C_DGLSolver::euler(double xstart, double xend, int anzahlSchritte, CMyVektor y_start, bool abweichung) {
    double h = (xend - xstart) / anzahlSchritte; // Calculate step size
    double start = xstart; // Initialize start variable with xstart
    int schritt = 0; // Initialize step counter

    CMyVektor ystart = y_start; // Initialize current y with start value
    CMyVektor ableitung = ableitungen(ystart, xstart); // Compute initial derivatives

    if (!abweichung) { // If deviation flag is false, print step size
        std::cout << "h = " << h << std::endl << std::endl;
    }

    while (true) {
        if (schritt == anzahlSchritte) { // If maximum steps reached
            if (!abweichung) { // If deviation flag is false, print final values
                std::cout << "Ende bei" << std::endl;
                std::cout << "\t" << "x = " << start << std::endl;
                std::cout << "\t" << "y = ( " << ystart.getComponent(0) << "; " << ystart.getComponent(1) << ")" << std::endl;
            }
            break; 
        }

        if (!abweichung) { // If deviation flag is false, print current step values
            std::cout << "Schritt " << schritt << ":" << std::endl;
            std::cout << "\t" << "x = " << start << std::endl;
            std::cout << "\t" << "y = ( " << ystart.getComponent(0) << "; " << ystart.getComponent(1) << ")" << std::endl;
        }

        ystart = ystart + h * ableitung; // Update y using Euler's method

        if (!abweichung) { // If deviation flag is false, print derivatives
            std::cout << "\t" << "y' = ( " << ableitung.getComponent(0) << "; " << ableitung.getComponent(1) << ")" << std::endl << std::endl;
        }

        start += h; // Increment x by step size
        ableitung = ableitungen(ystart, start); // Recompute derivatives
        schritt++; // Increment step counter
    }

    if (abweichung) { // If deviation flag is true, print deviation from 0.5
        std::cout << ystart.getComponent(0) - 0.5;
    }
}


void C_DGLSolver::heun(double xstart, double xend, int anzahlSchritte, CMyVektor y_start, bool abweichung) {
    double h = (xend - xstart) / anzahlSchritte; // Calculate step size
    double start = xstart; // Initialize start variable with xstart
    int schritt = 0; // Initialize step counter

    CMyVektor ystart = y_start; // Initialize current y with start value
    CMyVektor y_Test = ystart; // Initialize test y with start value
    CMyVektor y_Mittel = ystart; // Initialize average y with start value
    CMyVektor orig_ableitung = ableitungen(ystart, start); // Compute initial derivatives
    CMyVektor test_ableitung = orig_ableitung; // Initialize test derivatives with original derivatives

    if (!abweichung) { // If deviation flag is false, print step size
        std::cout << "h = " << h << std::endl << std::endl << std::endl;
    }

    while (true) {
        if (schritt == anzahlSchritte) { // If maximum steps reached
            if (!abweichung) { // If deviation flag is false, print final values
                std::cout << "Ende bei" << std::endl;
                std::cout << "\t" << "x = " << start << std::endl;
                std::cout << "\t" << "y = ( " << ystart.getComponent(0) << "; " << ystart.getComponent(1) << ")" << std::endl;
            }
            break; 
        }

        if (!abweichung) { // If deviation flag is false, print current step values
            std::cout << "Schritt " << schritt << ":" << std::endl;
            std::cout << '\t' << "x = " << start << std::endl;
            std::cout << "\t" << "y = ( " << ystart.getComponent(0) << "; " << ystart.getComponent(1) << ")" << std::endl;
            std::cout << "\t" << "y'_orig = ( " << orig_ableitung.getComponent(0) << "; " << orig_ableitung.getComponent(1) << ")" << std::endl << std::endl;
        }

        y_Test = ystart + h * orig_ableitung; // Compute test y using Euler's method
        test_ableitung = ableitungen(y_Test, start + h); // Compute derivative at test point
        y_Mittel = 0.5 * (orig_ableitung + test_ableitung); // Compute average derivative

        ystart = ystart + h * y_Mittel; // Update y using Heun's method
        start += h; // Increment x by step size

        if (!abweichung) { // If deviation flag is false, print test and average values
            std::cout << "\t" << "y_Test = ( " << y_Test.getComponent(0) << "; " << y_Test.getComponent(1) << ")" << std::endl;
            std::cout << "\t" << "y'_Test = ( " << test_ableitung.getComponent(0) << "; " << test_ableitung.getComponent(1) << ")" << std::endl;
            std::cout << "\t" << "y'_Mittel = ( " << y_Mittel.getComponent(0) << "; " << y_Mittel.getComponent(1) << ")" << std::endl << std::endl;
        }

        orig_ableitung = ableitungen(ystart, start); // Recompute initial derivative for next step
        schritt++; // Increment step counter
    }

    if (abweichung) { // If deviation flag is true, print deviation from 0.5
        std::cout << ystart.getComponent(0) - 0.5;
    }
}
