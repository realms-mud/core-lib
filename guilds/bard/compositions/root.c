//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/compositeActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        compositeActiveResearchItem::reset(arg);
        addSpecification("name", "Musical Compositions");
        addSpecification("source", "bard");
        addSpecification("description", "This skill provides the user with the "
            "knowledge of composing and playing songs that can provide "
            "complex effects.");

        addSpecification("limited by", ([
            "equipment": ({ "instrument: plucked", "instrument: bowed",
                "instrument: woodwind", "instrument: brass",
                "instrument: percussion" }) ]));

        addSpecification("composite rules", ([
            "template must be one of": ({
                "guilds/bard/compositions/aaa.c",
                "guilds/bard/compositions/aaba.c",
                "guilds/bard/compositions/abab.c",
                "guilds/bard/compositions/ababcb.c",
                "guilds/bard/compositions/abac.c",
                "guilds/bard/compositions/abacbaa.c",
                "guilds/bard/compositions/freeform.c",
                "guilds/bard/compositions/simple-ballad.c",
                "guilds/bard/compositions/verse-chorus-bridge.c",
                "guilds/bard/compositions/verse-pre-chorus.c",
            }),
        ]));

        addSpecification("scope", "self");
        addSpecification("research type", "tree root");
    }
}
