//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("swordsmith interior");

    addItemTemplate(
        "The swordsmith's shop is spare and precise, reflecting the exacting "
        "nature of the craft. A narrow forge burns white-hot at the rear, "
        "flanked by quenching baths of oil and brine. The central workbench "
        "holds an array of specialized tools - fullers, swages, draw knives, "
        "and fine-grit whetstones. Finished blades hang from a velvet-lined "
        "display rack: longswords with wire-wrapped grips, elegant rapiers, "
        "and a heavy hand-and-a-half sword with a deeply etched fuller. "
        "The air carries the sharp scent of quenching oil and heated steel."
    );

    addNearDarkDescriptionTemplate(
        "the swordsmith's shop is nearly black, the forge reduced to a "
        "faint white line at the rear and the blades invisible on their rack"
    );
    addLowLightDescriptionTemplate(
        "the glow of the forge barely reaches the display rack, where the "
        "blades are little more than dark lines against velvet"
    );
    addDimLightDescriptionTemplate(
        "dim light and the forge's glow reveal the elegant shapes of "
        "finished swords and the precise arrangement of the workbench"
    );
    addSomeLightDescriptionTemplate(
        "the swordsmith's shop is bright enough to admire the etched "
        "fullers, the wire-wrapped grips, and the keen edges of each blade"
    );
    addDescriptionTemplate(
        "light pours into the swordsmith's shop, running along every blade "
        "like liquid silver and illuminating the meticulous craft on display"
    );
}
