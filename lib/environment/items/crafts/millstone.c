//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("millstone");
    addAlias("grinding stone");
    addAlias("quern");
    addAlias("mill stone");

    addAdjectives(({ "massive", "granite", "grooved", "heavy",
        "ancient", "flour-dusted", "worn", "circular", "rumbling",
        "grey" }));

    addDescriptionTemplate("a ##Adjective## millstone set into the mill floor");

    addItemTemplate(
        "The millstone is a massive disc of granite, its grinding face cut "
        "with radiating furrows that channel the grain from center to edge "
        "as it is crushed. A thick wooden axle connects it to the drive "
        "mechanism, and a fine coat of flour dust covers every surface. "
        "The stone rumbles deeply when in motion."
    );

    addSomeLightDescriptionTemplate(
        "a massive granite millstone sits in the floor, dusted with flour"
    );
    addDimLightDescriptionTemplate(
        "a large circular stone is set into the floor, pale with flour dust"
    );
    addLowLightDescriptionTemplate(
        "a large round shape is set into the floor"
    );
    addNearDarkDescriptionTemplate(
        "the scent of ground flour and the feel of grit underfoot suggest "
        "a millstone nearby"
    );
}
