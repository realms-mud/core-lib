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
        addSpecification("type", "racial");
        addSpecification("name", "Celebnosti");
        addSpecification("description", "");
        addSpecification("root", "human");
        addSpecification("opposing root", "orc");
        addSpecification("opinion", 5);
        addSpecification("opposing opinion", -5);
        "baseTrait"::reset(arg);
    }
}

