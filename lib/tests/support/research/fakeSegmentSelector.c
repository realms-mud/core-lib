//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

/////////////////////////////////////////////////////////////////////////////
public mapping songData()
{
    return ([
        "name": "Song of the Weasels",
        "alias": "weasel",
        "constraint": "/guilds/bard/compositions/root.c",
        "type": "/guilds/bard/compositions/simple-ballad.c",
        "elements": ({
            (["research":"lib/tests/support/research/compositeResearchItemE.c",
                "type" : "intro",
                "description" : "Gittern, Cm7b5 arpeggio",
                "order in sequence" : 1
            ]),
        })
    ]);
}
