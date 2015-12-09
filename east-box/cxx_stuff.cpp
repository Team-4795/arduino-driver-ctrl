
extern "C" {
int __cxa_guard_acquire(void *g) {return !*(char *)(g);}
void __cxa_guard_release (void *g) {*(char *)g = 1;}
void __cxa_guard_abort (void *) {}
void __cxa_pure_virtual(void) {}
}

