//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("Rogue Hall");
    InteriorType("rogue hall");
    setFloorPlanType("guild");

    addTimeOfDayDescription("dawn", ({
        ". The guild hall is quiet at this hour, the flickering light from hidden lanterns casting long shadows. A few members linger in the shadows, awaiting the night's heist"
        }));
    addTimeOfDayDescription("morning", ({
        ". The shadows remain long in the early morning, the guild members sleeping off their late-night work. The only sounds are the quiet footfalls of those who remain alert"
        }));
    addTimeOfDayDescription("noon", ({
        ". The city above is bustling, but down here in the guild hall, the air is still, filled with hushed whispers and the soft clicking of locks being picked and daggers sharpened"
        }));
    addTimeOfDayDescription("afternoon", ({
        ". The members of the guild are just waking, stretching, and preparing for their work. Some practice sleight of hand, others polish blades or prepare poisons"
        }));
    addTimeOfDayDescription("evening", ({
        ". As the sun sets, the guild hall begins to stir with activity. Rogues and spies gather to discuss plans, exchange information, or prepare for their clandestine missions"
        }));
    addTimeOfDayDescription("dusk", ({
        ". The hall is lit by flickering lanterns and hidden torches, the shadows growing deeper. It's time for the guild members to head out on their assignments, either on foot or in disguise"
        }));
    addTimeOfDayDescription("night", ({
        " when the hall is alive with low murmurs and quiet footsteps. Members prepare to slip through the city unseen, execute heists, or assassinate targets under the cover of darkness"
        }));
    addTimeOfDayDescription("late night", ({
        " when only a few members remain in the guild hall, the quiet clinking of gold coins and the soft rustling of shadows the only sound. Plans are made, and rumors are traded"
        }));
    addTimeOfDayDescription("midnight", ({
        " when the guild hall is at its quietest, most members have returned with their spoils or secrets. The dim light of candles flickers in the distance as the guild readies for another night's work"
        }));

    addSeasonDescription("winter", ({
        " when the chill of the outside world makes the warmth of the guild hall feel even more like a sanctuary. The shadows grow long, and the guild hall feels more like a home than ever"
        }));
    addSeasonDescription("spring", ({
        " when the world outside comes to life. The guild hall, hidden beneath the earth, remains quiet, though the chatter about new jobs and contracts begins to grow"
        }));
    addSeasonDescription("summer", ({
        " when the heat from the city above seeps into the guild hall, making the air feel thick with anticipation. Rogues prepare for heists while the streets are full of visitors to the city"
        }));
    addSeasonDescription("autumn", ({
        " when the crisp air carries the scent of falling leaves and secrets. The members of the guild are busy planning and executing missions, knowing the city is ripe for theft during this time"
        }));

    addSourceOfLight(4, "lanterns, hidden torches, and the dim glow of enchanted candles", "night");

    addDescriptionTemplate("an underground lair beneath a tavern or in the depths of the city, filled with hidden rooms and passageways, illuminated by low, flickering light");
    addNearDarkDescriptionTemplate("a shadowy, dimly lit building, the faintest light seeping through cracks in the floorboards, with hidden entrances and whispering figures");
    addLowLightDescriptionTemplate("a dark, labyrinthine network of rooms and corridors, where thieves and assassins move silently through the shadows");
    addDimLightDescriptionTemplate("an underground lair full of murmurs and whispers, where members of the guild gather to exchange information or plan their next heist");
    addSomeLightDescriptionTemplate("a hidden, secluded space beneath the city, where flickering lanterns cast dancing shadows on stone walls and guild members gather in secret");
}