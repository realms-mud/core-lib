//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "personality");
        addSpecification("name", "deranged");
        addSpecification("description", "Calling you insane is unfair to "
            "the crazies and psychopaths in the looney bin. You're on "
            "another level; the type of person who might be seen strangling "
            "puppies outside of an orphanage whilst wearing nothing but a "
            "deer antler helmet and a leering grin.");
        addSpecification("root", "insane");
        addSpecification("opposing root", "sane");
        addSpecification("opinion", -25);
        addSpecification("opposing opinion", -50);
        addSpecification("penalty to persuasion", 1);
        addSpecification("penalty to diplomacy", 1);
        addSpecification("bonus intimidation", 3);
        addSpecification("penalty to etiquette", 1);
        addSpecification("penalty to bluff", 1);
        "baseTrait"::reset(arg);
    }
}
