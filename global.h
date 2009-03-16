#ifndef SB_NAMEPSACE_STD___
#define SB_NAMESPACE_STD___
using namespace std;
#endif

#ifndef SB_VECT2
#define SB_VECT2
struct Vect2 {
	Vect2(): x(0), y(0) {}
	Vect2(int in_x, int in_y): x(in_x), y(in_y) {}
	int x, y;
};
#endif

#include "macros.h"

#ifndef SB_CURSES_H___
#define SB_CURSES_H___
#include <curses.h>
#endif

#ifndef SB_STD_LIB___
#define SB_STD_LIB___
#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <stdio.h>
#endif

#ifndef SB_PANEL_H___
#define SB_PANEL_H___
#include <panel.h>
#endif

#ifndef SB_SIGNAL_H___
#define SB_SIGNAL_H___
#include <signal.h>
#endif

//#include "toolkit.h"

#ifndef SB_VECT3
#define SB_VECT3
struct Vect3 {
	Vect3(): x(0), y(0), z(0) {}
	Vect3(int in_x, int in_y, int in_z): x(in_x), y(in_y), z(in_z) {}
	int x, y, z;
};
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef NULL
#define NULL (void*)0
#endif
