//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("garderobe");
    addAlias("latrine");
    addAlias("privy");
    addAlias("toilet");

    addAdjectives(({ "stone", "narrow", "cold", "enclosed", "simple", "old",
        "worn", "drafty", "recessed", "functional" }));

    addDescriptionTemplate("a ##Adjective## garderobe set into the wall");

    addItemTemplate(
        "This garderobe is a narrow, stone-walled recess with a wooden seat "
        "set over a chute. The stone is cold and worn smooth by years of use, "
        "and a small opening in the wall allows for ventilation."
    );

    addSomeLightDescriptionTemplate(
        "a stone garderobe is set into the wall, its seat worn by long use"
    );
    addDimLightDescriptionTemplate(
        "a narrow garderobe is visible in the gloom, its outline plain"
    );
    addLowLightDescriptionTemplate(
        "a faint shape of a garderobe can be made out, little more than a shadow"
    );
    addNearDarkDescriptionTemplate(
        "a vague shadow suggests a garderobe is present, but details are lost "
        "in the darkness"
    );
}
