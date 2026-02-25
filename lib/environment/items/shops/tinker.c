//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("tinker interior");

    addItemTemplate(
        "The tinker's shop is a fascinating clutter of gears, springs, and "
        "half-assembled mechanisms. A heavy workbench dominates the center, "
        "its surface covered with jeweler's loupes, fine-tipped pliers, "
        "tweezers, and tiny brass screws sorted into compartmented trays. "
        "Shelves display the tinker's wares: intricate clockwork music boxes, "
        "self-winding lantern mechanisms, combination locks, and a delicate "
        "orrery whose brass planets orbit a golden sun. Coils of copper wire, "
        "sheets of tin, and jars of watchmaker's oil fill the remaining space. "
        "The shop ticks and whirrs softly with the quiet life of a dozen "
        "mechanisms running at once."
    );

    addNearDarkDescriptionTemplate(
        "the tinker's shop is lost in darkness, though the soft ticking and "
        "whirring of unseen mechanisms fills the silence"
    );
    addLowLightDescriptionTemplate(
        "the tinker's workbench is a dim shape surrounded by the quiet "
        "sounds of clockwork, brass faintly glinting on the shelves"
    );
    addDimLightDescriptionTemplate(
        "soft light catches the brass gears and mechanisms on the shelves, "
        "and the orrery's tiny planets gleam as they slowly orbit"
    );
    addSomeLightDescriptionTemplate(
        "the tinker's shop is bright enough to admire the intricate "
        "clockwork devices and the fine tools arrayed on the workbench"
    );
    addDescriptionTemplate(
        "light fills the tinker's shop, making every gear, spring, and "
        "polished brass surface gleam with mechanical precision"
    );
}
