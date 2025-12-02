//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("Pyromancer's Guild Hall");
    InteriorType("towering citadel of flames");
    setFloorPlanType("guild");

    addTimeOfDayDescription("dawn", ({
        ". As the sun rises, the guild hall glows faintly, lit by the embers of smoldering fires from the night before. The air crackles with the residual heat of the pyromancers' late-night experiments"
        }));
    addTimeOfDayDescription("morning", ({
        ". The rising light mingles with the vibrant flames in the central atrium, casting long shadows and warming the air as mages conduct their studies and prepare for the day's work"
        }));
    addTimeOfDayDescription("noon", ({
        ". The sun is high, and the central chamber of the guild hall pulses with intense heat and light. Pyromancers can be seen conjuring flames for various magical tests and practical applications"
        }));
    addTimeOfDayDescription("afternoon", ({
        ". The heat of the day brings a shimmering haze to the air within the guild. Pyromancers practice fire-based spells in the courtyard, and the very ground seems to hum with energy"
        }));
    addTimeOfDayDescription("evening", ({
        ". As the sun sets, the guild hall is bathed in the glow of enchanted fires, their dance casting flickering shadows that swirl with the heat of the coming night"
        }));
    addTimeOfDayDescription("dusk", ({
        ". The warm glow of magical flames illuminates the hall, as the pyromancers gather around their cauldrons and flame-churning devices to prepare for their nightly rituals"
        }));
    addTimeOfDayDescription("night", ({
        " when the guild hall is alight with the magic of fire, its chambers aglow with the colors of magical flame. The pyromancers are busy with their final experiments before rest"
        }));
    addTimeOfDayDescription("late night", ({
        " when only the steady crackling of flames fills the guild hall, and the air is thick with the scent of burning incense and the heat of fire spells that linger long into the night"
        }));
    addTimeOfDayDescription("midnight", ({
        " when the guild hall is bathed in the eerie light of smoldering embers and faintly glowing magical flames, as pyromancers work quietly on their most dangerous and secretive rituals"
        }));

    addSeasonDescription("winter", ({
        " when the cold air outside is kept at bay by the roaring hearths and magical fires that blaze throughout the guild, ensuring that the warmth of the pyromancers' craft is always felt"
        }));
    addSeasonDescription("spring", ({
        " when the guild hall seems to hum with new energy, the warming firelight bringing a sense of vitality and renewal as pyromancers work to control and perfect new, vibrant flame spells"
        }));
    addSeasonDescription("summer", ({
        " when the heat inside the guild hall becomes almost unbearable, but the pyromancers are unphased, thriving in the fiery temperatures as they craft and shape fire magic with ease"
        }));
    addSeasonDescription("autumn", ({
        " when the flickering flames seem to dance with an orange-red intensity, casting long shadows that reflect the changing season, as pyromancers experiment with new fiery techniques"
        }));

    addSourceOfLight(7, "magical flames, fire conjurations, and enchanted torches", "night");

    addDescriptionTemplate("a towering citadel of fire, where the heat of magical flames burns brightly, and pyromancers practice the art of flame and heat manipulation");
    addNearDarkDescriptionTemplate("a glowing citadel, the flickering light of magical fire illuminating the stone walls and casting dancing shadows across the entrance");
    addLowLightDescriptionTemplate("a towering structure where flame magic radiates from every corner, the warmth of the fire filling the air and heating the stone halls");
    addDimLightDescriptionTemplate("a citadel suffused with magical firelight, where the flickering glow of flames dances across every surface and the air hums with energy");
    addSomeLightDescriptionTemplate("a grand hall illuminated by the flickering flames of fire magic, where pyromancers practice their art and the heat of their power fills the air");
}
