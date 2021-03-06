/* See LICENSE in the main directory for copyright. */
/* for func prototypes */
#include "util.h"
/* for bricks logging */
#include "bricks_log.h"
/* pthread w/ affinity */
#include <pthread_np.h>
/* cpu_set */
#include <sys/cpuset.h>
/*---------------------------------------------------------------------*/
/**
 * Affinitizes current thread to the specified cpu
 */
int
set_affinity(int cpu, pthread_t *t)
{
	TRACE_UTIL_FUNC_START();
	cpuset_t cpus;

	
	/* if cpu affinity was not specified */
	if (cpu < 0) {
		TRACE_UTIL_FUNC_END();
		return 0;
	}
	CPU_ZERO(&cpus);
	CPU_SET((unsigned)cpu, &cpus);
		
	if (pthread_setaffinity_np(*t, sizeof(cpus), &cpus)) {
		TRACE_LOG("Unable to affinitize thread %u to core %d\n",
			  *((unsigned int *)t), cpu);
		TRACE_UTIL_FUNC_END();
		return -1;
	}

	TRACE_UTIL_FUNC_END();	
	return 0;
}
/*---------------------------------------------------------------------*/
