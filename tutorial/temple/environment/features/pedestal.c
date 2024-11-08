//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("runed pedestal");
    suppressEntryMessage();

    addDescriptionTemplate("along the wall near the entry, many "
        "intricate runes have been carved. In the center of the "
        "liquid-free area stand four three-foot tall pedestals. "
        "Each has been placed at a cardinal point and about a ten "
        "foot gaps stands between one to its nearest "
        "neighbor. Scintilating orbs of energy sit atop each "
        "pedestal, pulsating with magical energies.\n"
        "##call_other::key::/tutorial/temple/objects/pedestal.c::displayOrbs::"
        "Beside each of the pedestals, a glowing circle of etched "
        "stone lies: to the north, blue; to the south, red; to the "
        "east, green; and to the west, white. In the middle of all "
        "the pedestals, another sits, emitting a sickly black "
        "glow");
    addSourceOfLight(10);

    addAlias("pedestals");

    addItemTemplate("All of the pedestals appear to be of the same nature - "
        "about three feet tall, they appear to have been formed "
        "of the same amethyst from which the whole room was formed.");
}
