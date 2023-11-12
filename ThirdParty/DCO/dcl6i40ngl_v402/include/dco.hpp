// dco/c++ version: v4.0.2
// branch: 4.0.2
// used DCO_FLAGS: -DDCO_SCRAMBLE -DDCO_LICENSE

// ================================================================ //
// *** This is a generated file from above given source version *** //
// ================================================================ //
#ifndef DCO_HPP
#define DCO_HPP

#ifdef _MSC_VER
#pragma warning( push )
#pragma warning( disable: 4512 )
#pragma warning( disable: 4503 )
#pragma warning( disable: 4127 )
#pragma warning( disable: 4355 )
#endif

//** Required for avoiding multiple definitions; we know this file is
//** included in the generated header. So let's avoid it to be
//** included again from the generated file.
#ifdef DCO_CODEGEN_HELPER_HPP
#error "dco/c++ error: if including dco/c++ codegen generated files and dco.hpp, include dco.hpp before any of the generated ones."
#endif

#include "dco_interoperability_eigen.hpp"

#include "dco_configuration.hpp"
#include "dco_global_includes.hpp"
#include "dco_logging.hpp"

#ifdef DCO_NO_INTERMEDIATES
#include "dco_inc_noet.hpp"
#else
#include "dco_inc.hpp"
#endif

#include "dco_vector.hpp"

#include "dco_std_compatibility.hpp"
#include "dco_allocation_helper.hpp"

#include "dco_interoperability_eigen_spec.hpp"
#include "dco_interoperability_boost_interval.hpp"

#ifdef _MSC_VER
#pragma warning( pop )
#endif

//** Required for avoiding multiple definitions; we know this file is
//** included in the generated header. So let's avoid it to be
//** included again from the generated file.
#define DCO_CODEGEN_HELPER_HPP

#endif  
