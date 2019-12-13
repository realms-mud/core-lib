//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "personality");
        addSpecification("name", "petulant");
        addSpecification("description", "You're prone to react to situations "
            "where you don't get your way in an overly sullen, childish "
            "manneer.");
        addSpecification("root", "harsh");
        addSpecification("opposing root", "kind");
        addSpecification("opinion", -10);
        addSpecification("opposing opinion", -15);
        addSpecification("penalty to persuasion", 1);
        addSpecification("penalty to diplomacy", 1);
        addSpecification("penalty to intimidation", 1);
        "baseTrait"::reset(arg);
    }
}
