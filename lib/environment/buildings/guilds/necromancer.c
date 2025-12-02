//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("Necromancer Guild Hall");
    InteriorType("shadowy crypts and forbidden chambers");
    setFloorPlanType("guild");

    addTimeOfDayDescription("dawn", ({
        ". The first light of dawn barely touches the guild hall, as mist clings to the stone walls and the eerie silence is broken only by the soft rustle of ancient scrolls"
        }));
    addTimeOfDayDescription("morning", ({
        ". The sun's light is dimmed by the thick, ever-present fog surrounding the guild hall, as necromancers silently prepare for their daily rituals, casting faint shadows as they move"
        }));
    addTimeOfDayDescription("noon", ({
        ". The midday sun is muted and distant, but inside the guild hall, the air is thick with the scent of incense and the distant sound of whispers from otherworldly realms"
        }));
    addTimeOfDayDescription("afternoon", ({
        ". The halls of the guild grow darker as the sun sets outside, the smell of decay and ancient tomes permeating the air while members of the guild study forbidden rites"
        }));
    addTimeOfDayDescription("evening", ({
        ". As night draws closer, the guild hall becomes alive with the whispering of spirits and the rustling of parchment, as necromancers prepare for their dark rituals"
        }));
    addTimeOfDayDescription("dusk", ({
        ". The air is charged with necromantic energy as the last rays of the sun flicker over the guild's stone walls, and the first whispers of the dead are heard in the chambers"
        }));
    addTimeOfDayDescription("night", ({
        " when the guild hall is fully shrouded in darkness, lit only by the eerie glow of necromantic sigils, and the hushed murmurs of necromancers performing their rituals fill the air"
        }));
    addTimeOfDayDescription("late night", ({
        " when the moonlight casts an ethereal glow over the cryptic architecture, and necromancers commune with spirits, their dark incantations reverberating through the halls"
        }));
    addTimeOfDayDescription("midnight", ({
        " when the guild hall is cloaked in deep shadows, and the necromancers' work becomes truly dangerous, their dark magic rising to its fullest power, raising the dead from their graves"
        }));

    addSeasonDescription("winter", ({
        " when the guild hall is buried beneath a blanket of snow, the cold only adding to the chilling atmosphere, as the winds outside howl like the spirits of the lost"
        }));
    addSeasonDescription("spring", ({
        " with the first signs of decay appearing as plants wither under the unnatural influence of the necromantic magic that permeates the hall"
        }));
    addSeasonDescription("summer", ({
        " when the oppressive heat only serves to enhance the sense of death and decay that fills the halls, as necromancers grow stronger in their dark arts"
        }));
    addSeasonDescription("autumn", ({
        " with the falling leaves and the scent of death in the air, the guild hall comes alive with necromantic energy, as the veil between the living and the dead grows thin"
        }));

    addSourceOfLight(4, "flickering candles and necromantic sigils", "night");

    addDescriptionTemplate("a dark, foreboding guild hall dedicated to the study and mastery of necromancy, where death itself is revered");
    addNearDarkDescriptionTemplate("a looming, oppressive structure, its silhouette barely visible through the thick fog and shadow, with faint flickers of magical light seeping from the windows");
    addLowLightDescriptionTemplate("a dimly lit hall, filled with ancient books, ritualistic symbols, and the faint whispers of spirits that haunt the guild's chambers");
    addDimLightDescriptionTemplate("a guild hall steeped in shadow, where necromancers commune with the dead and practice forbidden rites, casting eerie shadows across the halls");
    addSomeLightDescriptionTemplate("an imposing, death-infused tower, where the secrets of necromancy are studied and death itself is manipulated by those who dare to tread its halls");
}