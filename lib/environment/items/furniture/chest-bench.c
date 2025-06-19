//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseContainer.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("chest bench");
    addAlias("bench");
    addAlias("storage bench");
    addAlias("wooden chest bench");

    addAdjectives(({ "wooden", "broad", "carved", "old", "sturdy", "plain",
        "functional", "worn", "panelled", "long" }));

    addDescriptionTemplate("a ##Adjective## chest bench with a hinged seat");

    addItemTemplate(
        "This chest bench is made from sturdy wood, its seat lifting to reveal "
        "a spacious storage compartment. The sides are panelled and the legs "
        "are thick and stable."
    );

    addSomeLightDescriptionTemplate(
        "a wooden chest bench stands along the wall, its seat closed"
    );
    addDimLightDescriptionTemplate(
        "a chest bench is visible in the gloom, its outline long and broad"
    );
    addLowLightDescriptionTemplate(
        "a faint shape of a chest bench can be made out, little more than a shadow"
    );
    addNearDarkDescriptionTemplate(
        "a vague shadow suggests a chest bench is present, but details are lost "
        "in the darkness"
    );
}
