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
        addSpecification("name", "frail");
        addSpecification("description", "You have a below normal constitution.");
        addSpecification("root", "sickly");
        addSpecification("opposing root", "hale");
        addSpecification("opinion", -5);
        addSpecification("penalty to constitution", 2);
        addSpecification("penalty to heal hit points", 1);
        addSpecification("cost", -1);
        "baseTrait"::reset(arg);
    }
}

