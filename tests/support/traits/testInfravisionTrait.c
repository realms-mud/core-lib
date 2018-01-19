//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, Realms MUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "health");
        addSpecification("name", "Infravision");
        addSpecification("description", "blah blah blah");
        addSpecification("root", "infravision");
        "baseTrait"::reset(arg);
    }
}
