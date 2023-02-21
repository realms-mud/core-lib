//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "genetic");
    addSpecification("name", "Freak");
    addSpecification("description", "blah blah blah");
    addSpecification("root", "disfigured");
    addSpecification("opposing root", "normal");
    addPrerequisite("long sword", (["type":"skill", "value" : 10]));
}
