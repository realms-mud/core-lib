//*****************************************************************************
// Class: realization
// File Name: realization.c
//
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
private nosave string Realizations = "lib/realizations";

//-----------------------------------------------------------------------------
// Method: isRealizationOf
// Description: This method returns the module object for the queried type of
//              realization if it has been integrated with this instance. It
//              is EXTREMELY important to understand the security ramifications
//              of this method. For example, it is not enough to simply call
//              this method to check if an object is a wizard. While calls to
//              anything inheriting realization / residing in this directory
//              would work as intended, this would not prevent a sinister
//              wizard from creating a custom object with the proper 
//              isRealizationOf method added and through it being able to get
//              wizardly access to stuff. Every secure thing created MUST do
//              checks similar to this on their (consuming) end.
//
// Parameters: type - the type of realization to check for
//
// Returns: the realization object if this object is of the correct type.
//-----------------------------------------------------------------------------
public nomask object isRealizationOf(string type)
{
    object ret = 0;
    if((member(inherit_list(), sprintf("%s/%s.c",  Realizations, type)) > -1) &&
        function_exists(sprintf("isRealizationOf%s", capitalize(type))) &&
        call_other(this_object(), sprintf("isRealizationOf%s", capitalize(type))))
    {
        ret = this_object();
    }
    return ret;
}
