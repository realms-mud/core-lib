//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("ruin entry");

    addAdjectives(({
        "derelict entry with crumbling walls and shattered marble tiles",
        "formerly grandiose atrium where stone walls are now in disrepair and "
            "ivy creeps through cracks",
        "grand atrium where small piles of debris have fallen from once "
            "artfully-crafted walls now stained by time",
        "crumbling entry where the battered walls have seen better days and "
            "ceiling timbers hang precariously",
        "ruined entry with pockmarked walls and columns split by centuries of neglect",
        "long-neglected atrium where weeds push through the fractured floor",
        "collapsed entryway where fallen stones and rotted beams block portions "
            "of the passage",
        "decayed vestibule where rain pools among the broken floor tiles",
        "broken, ancient entrance hall whose faded murals hint at long-forgotten glory",
        "deteriorating foyer where every footstep echoes through empty archways",
        "time-ravaged antechamber with a partially collapsed ceiling open to the sky",
        "weathered entrance where wind whistles through missing windows and doors",
        "skeletal reception hall stripped of all ornamentation by looters and time",
        "sunken atrium where the floor has subsided creating treacherous footing",
        "moss-covered entry chamber where nature reclaims what was once magnificent",
        "broken threshold where carved reliefs crumble at the slightest touch",
        "hollow entrance where the sound of dripping water echoes endlessly",
        "ghostly foyer where dust motes dance in shafts of light through cracked walls",
        "shattered entry hall where fallen chunks of masonry create a maze-like path",
        "vestibule where centuries of wind and rain have smoothed the stone"
        }));

    useExteriorLighting();

    addDescriptionTemplate("a ##Adjective##");

    addNearDarkDescriptionTemplate(
        "a shadowy ruin entry barely visible in the darkness, where only the "
        "outlines of fallen stones and gaping doorways can be dimly perceived. "
        "The sound of small creatures scurrying across unseen debris is "
        "occasionally audible in the stillness"
    );

    addLowLightDescriptionTemplate(
        "a dark entrance hall where weak light filters through cracks and "
        "collapsed sections, revealing hints of toppled columns and crumbling "
        "archways. The extent of the decay is mercifully obscured by shadow"
    );

    addDimLightDescriptionTemplate(
        "a dimly-lit ##Adjective##, where faint light reveals centuries of "
        "decline. Dust hangs in the air, and the remnants of what might have "
        "once been impressive architectural features loom in the half-light"
    );

    addSomeLightDescriptionTemplate(
        "a well-illuminated ##Adjective##. In the clear light, every crack and "
        "crevice is visible, from the weathered floor tiles to the crumbling "
        "ceiling. Particles of dust drift through shafts of sunlight that "
        "pierce holes in the structure"
    );
}
