//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/support/research/testActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "blueprint practice");
    addSpecification("source", "test");
    addSpecification("research type", "granted");
    addSpecification("scope", "self");
    addSpecification("command template", "practice blade");
    addSpecification("limited by", ([
        "equipment":([ "blueprint":"katana" ])
    ]));
}
