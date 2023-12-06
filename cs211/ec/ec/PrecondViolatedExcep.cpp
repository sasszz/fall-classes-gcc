//
//  PrecondViolatedExcep.cpp
//  ec
//
//  Created by Lucie Chevreuil on 12/6/23.
//

#include "PrecondViolatedExcep.h"

PrecondViolatedExcep::PrecondViolatedExcep(const string& message) : logic_error("Precondition Violated Exception: " + message)
{
}  // end constructor

// End of implementation file.
