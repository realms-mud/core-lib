//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "personality");
        addSpecification("name", "orator");
        addSpecification("description", "You are a brilliant tactician when it comes to speech. It's rumored that you can even talk a dog out of its meal.");
        addSpecification("root", "eloquent");
        addSpecification("opposing root", "vulgar");
        addSpecification("opinion", 15);
        addSpecification("bonus persuasion", 2);
        "baseTrait"::reset(arg);
    }
}

