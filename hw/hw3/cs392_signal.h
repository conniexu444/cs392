/**
 * Constance Xu
 * I pledge my honor that I have abided by the Stevens Honor System.
*/
#ifndef CS392_SIGNAL_H
#define CS392_SIGNAL_H

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

static void handler(int, siginfo_t*, void*);
void reg_handler();

#endif