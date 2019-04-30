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
        addSpecification("name", "foul");
        addSpecification("description", "You are a rather unrefined and "
            "ill-mannered lout.");
        addSpecification("root", "harsh");
        addSpecification("opposing root", "refined");
        addSpecification("opinion", -5);
        addSpecification("opposing opinion", -10);
        addSpecification("penalty to persuasion", 1);
        addSpecification("penalty to diplomacy", 1);
        addSpecification("penalty to etiquette", 1);
        "baseTrait"::reset(arg);
    }
}
