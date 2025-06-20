//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("lattice window");
    addAlias("window");
    addAlias("latticed window");

    addItemTemplate(
        "The window is framed with a delicate wooden lattice, its crisscrossed "
        "pattern holding small panes of glass. The latticework casts intricate "
        "shadows on the floor when the light is right."
    );

    addNearDarkDescriptionTemplate(
        "the outline of a lattice window is barely visible, its pattern lost "
        "in the gloom"
    );
    addLowLightDescriptionTemplate(
        "a lattice window glimmers faintly, its pattern just visible in the "
        "dim light"
    );
    addDimLightDescriptionTemplate(
        "a lattice window lets in a pale glow, the crisscrossed pattern "
        "casting faint shadows"
    );
    addSomeLightDescriptionTemplate(
        "soft daylight filters through the lattice window, creating a web of "
        "light and shadow"
    );
    addDescriptionTemplate(
        "sunlight streams through the lattice window, painting the room with "
        "intricate patterns"
    );
    useExteriorLighting();
}
