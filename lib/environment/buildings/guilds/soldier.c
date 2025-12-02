//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("Soldier Guild");
    InteriorType("training fortress");
    setFloorPlanType("guild");

    addTimeOfDayDescription("dawn", ({
        ". The first light of day shines over the guild's barracks. Soldiers begin their morning drills, their disciplined movements echoing through the courtyard. The air is filled with the sound of swords striking shields"
        }));
    addTimeOfDayDescription("morning", ({
        ". The guild is alive with activity as soldiers sharpen their weapons, don their armor, and prepare for their daily drills. The sounds of marching and commands fill the air, as the warriors ready themselves for the day's tasks"
        }));
    addTimeOfDayDescription("noon", ({
        ". The training grounds are bustling with activity as soldiers engage in sparring matches, practicing their combat techniques with swords, spears, and shields. The air is filled with the sound of steel clashing"
        }));
    addTimeOfDayDescription("afternoon", ({
        ". Soldiers gather in small groups, discussing tactics and strategy in preparation for their next campaign. Some practice formations, while others polish their weapons or clean their armor"
        }));
    addTimeOfDayDescription("evening", ({
        ". The sun begins to set, casting long shadows across the courtyard. Soldiers wind down their training, gathering in the mess hall or the common areas to eat and rest after a long day's work"
        }));
    addTimeOfDayDescription("dusk", ({
        ". The guild hall is quiet as the last few soldiers return to their barracks for the night. The command center remains open, where generals and commanders discuss plans for future campaigns or tactical operations"
        }));
    addTimeOfDayDescription("night", ({
        " when the guild hall grows silent. Most soldiers are in their barracks, resting for the next day's training. The faint glow of lanterns can be seen from the command center, where strategy discussions continue late into the night"
        }));
    addTimeOfDayDescription("late night", ({
        " when only a few guards patrol the halls. The soldier guild's barracks are quiet, the sound of armor shifting in sleep, while high-ranking officers deliberate in private rooms or war chambers"
        }));
    addTimeOfDayDescription("midnight", ({
        " when the guild hall is nearly still. The only noise comes from the distant sound of guards pacing the perimeter, and the occasional murmur of commanders preparing for tomorrow's drills"
        }));

    addSeasonDescription("winter", ({
        " when the cold winds blow through the stone walls of the guild. Soldiers bundle up in furs and warm clothing between drills. The training ground becomes a more harsh and challenging place, testing the endurance of the warriors"
        }));
    addSeasonDescription("spring", ({
        " when the grass in the courtyard begins to green, and soldiers increase their training. Marching drills, archery practice, and mock battles are common as the warriors prepare for summer campaigns"
        }));
    addSeasonDescription("summer", ({
        " when the sun beats down on the training grounds, and soldiers sweat through grueling drills. The guild hall fills with the clanging of weapons and armor as the warriors hone their skills for the upcoming war season"
        }));
    addSeasonDescription("autumn", ({
        " when the guild prepares for the upcoming cold. Soldiers are busy perfecting their formations and testing their endurance. The weather is cooler, and soldiers train harder to stay sharp for any conflict"
        }));

    addSourceOfLight(4, "torches, lanterns, and magical light sources", "night");

    addDescriptionTemplate("a large stone fortress with banners flying, the sounds of marching feet, clashing swords, and tactical discussions filling the air");
    addNearDarkDescriptionTemplate("a stone structure with low-lit windows, guards standing watch, and the sounds of soldiers in training within");
    addLowLightDescriptionTemplate("a military barracks with low light from lanterns, soldiers gathered around in quiet conversation or cleaning their weapons");
    addDimLightDescriptionTemplate("a solid stone building, with dimly lit hallways and the distant sounds of soldiers preparing for battle");
    addSomeLightDescriptionTemplate("a large guild hall with banners of the guild proudly displayed, filled with the sounds of training, sparring, and the commander's orders ringing out across the grounds");
}
