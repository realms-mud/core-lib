//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "health");
        addSpecification("name", "insane");
        addSpecification("description", "You are, quite simply, a lunatic. A madperson. Bonkers. "
            "Crazy. Your general insanity will be honed as you progress through the game, "
            "potentially unconvering schizophrenia, dissociative behavior, paranoia, megalomania, "
            "echopraxia, intense phobias, homicidal tendencies, and others");
        addSpecification("root", "sickly");
        addSpecification("opposing root", "hale");
        addSpecification("opinion", -25);
        addSpecification("penalty to wisdom", 2);
        addSpecification("penalty to persuasion", 5);
        addSpecification("research tree", "lib/instances/research/insaneResearchTree.c");
        addSpecification("cost", -2);
        "baseTrait"::reset(arg);
    }
}

