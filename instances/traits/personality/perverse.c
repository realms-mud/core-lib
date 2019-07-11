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
        addSpecification("name", "perverse");
        addSpecification("description", "You have a deliberate, stubborn "
            "desire to behave in ways that are quite unacceptable by "
            "societal standards and you seem to not particularly care "
            "what the consequences might be.");
        addSpecification("root", "perverse");
        addSpecification("opinion", -10);
        addSpecification("penalty to persuasion", 1);
        addSpecification("penalty to diplomacy", 1);
        addSpecification("penalty to etiquette", 1);
        "baseTrait"::reset(arg);
    }

}
