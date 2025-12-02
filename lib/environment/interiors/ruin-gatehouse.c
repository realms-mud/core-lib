//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("ruin gatehouse");

    addAdjectives(({
        "derelict gatehouse with crumbling walls and rusted portcullis mechanisms",
        "previously-formidable gatehouse where defensive arrow slits are now widened "
            "by centuries of decay",
        "long-abandoned guard post where weathered stone has worn away under "
            "relentless seasons",
        "crumbling gatehouse where the battered walls have seen better days "
            "and roof timbers hang precariously",
        "ruined gatehouse with pockmarked walls and fallen battlements",
        "long-neglected gatehouse where weeds grow from cracks in the stonework",
        "very ancient defensive structure where only hints remain of its former strength",
        "shattered gatehouse where the great wooden doors have long since rotted away",
        "defenseless entrance where broken murder holes stare down like empty eyes",
        "skeletal checkpoint where only the stone bones of once-imposing towers remain",
        "weathered guardhouse where wind whistles through the empty sockets of "
            "former windows",
        "fallen gatehouse where scattered stones mark where walls once stood proud",
        "haunting entrance chamber where guardsmen's footsteps echo only in memory",
        "breached fortification where nature has reclaimed what men once defended",
        "decrepit watchpost where rusting iron hinges mark the absence of mighty gates",
        "broken gateway where centuries of battle and neglect have left little standing",
        "now-unstable defensive position where ceilings threaten to collapse at any moment",
        "much-eroded checkpoint where rain and frost have worn smooth the once-sharp edges",
        "forsaken entryway where defensive features now lie scattered across the ground",
        "precarious gatehouse where climbing vines pull stones from their mortar beds"
        }));

    useExteriorLighting();

    addDescriptionTemplate("a ##Adjective##");

    addNearDarkDescriptionTemplate(
        "a shadowy ruin gatehouse barely visible in the darkness, where only "
        "the jagged outlines of collapsed walls and empty doorframes can be "
        "dimly perceived. The mechanism that once raised the portcullis lies "
        "broken and twisted in darkness"
    );

    addLowLightDescriptionTemplate(
        "a dark gatehouse where weak light filters through collapsed sections "
        "of wall and ceiling, revealing hints of defensive architecture now "
        "rendered useless by time. Arrow slits gape wider than intended, and "
        "the murder holes above offer no threat"
    );

    addDimLightDescriptionTemplate(
        "a dimly-lit ##Adjective##, where faint light reveals the remnants of "
        "a once-imposing defensive structure. The shadows cast by broken walls "
        "stretch across floors where armored guards once stood vigilant"
    );

    addSomeLightDescriptionTemplate(
        "a well-illuminated ##Adjective##. In the clear light, the full extent "
        "of the ruin is visible - from fallen stones that once formed thick walls "
        "to the broken chains and gears of the portcullis mechanism. Birds nest "
        "in crevices where soldiers once watched for approaching enemies"
    );
}
