//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, Realms MUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/prerequisites.c";

/////////////////////////////////////////////////////////////////////////////
public varargs int AddTestPrerequisite(string key, mapping prerequisite, string grouping)
{
    return addPrerequisite(key, prerequisite, grouping);
}


