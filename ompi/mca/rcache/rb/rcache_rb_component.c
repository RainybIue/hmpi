#include "mca/rcache/rcache.h"
#include "rcache_rb.h"

static int mca_rcache_rb_component_open(void); 

static mca_rcache_base_module_t* mca_rcache_rb_component_init( void ); 

mca_rcache_rb_component_t mca_rcache_rb_component = {
    {
        /* Indicate that we are a rcache v1.0.0 component (which also
           implies a specific MCA version) */
        
        MCA_RCACHE_BASE_VERSION_1_0_0,
        "rcache", /* MCA component name */
        OMPI_MAJOR_VERSION,  /* MCA component major version */
        OMPI_MINOR_VERSION,  /* MCA component minor version */
        OMPI_RELEASE_VERSION,  /* MCA component release version */
        mca_rcache_rb_component_open,  /* component open  */
        NULL
    },
    
    /* Next the MCA v1.0.0 component meta data */
    
    {
        /* Whether the component is checkpointable or not */
        false
    },
    mca_rcache_rb_component_init
};


static int mca_rcache_rb_component_open(void)
{
    return OMPI_SUCCESS; 
}

mca_rcache_base_module_t* mca_rcache_rb_component_init(void) {
    mca_rcache_rb_module_t* rcache; 
    rcache = (mca_rcache_rb_module_t*) malloc(sizeof(mca_rcache_rb_module_t));
    mca_rcache_rb_module_init(rcache); 
    return &rcache->base; 
}


