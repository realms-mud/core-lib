//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("Fist of Aranac Monastery");
    InteriorType("stone temple and meditation halls");
    setFloorPlanType("guild");

    addTimeOfDayDescription("dawn", ({
        ". The first rays of light gently touch the stone walls, casting long shadows across the courtyard where the monks begin their morning rituals"
        }));
    addTimeOfDayDescription("morning", ({
        ". The sound of monks chanting echoes from within the temple, as the scent of incense fills the air and the soft tap of bare feet on stone rings through the halls"
        }));
    addTimeOfDayDescription("noon", ({
        ". The temple's courtyard is bathed in sunlight, where the monks practice their martial forms in perfect unison, their movements graceful and precise"
        }));
    addTimeOfDayDescription("afternoon", ({
        ". The courtyard becomes quieter as the monks retreat into meditation chambers, and the faint sound of bells rings from the temple's tower"
        }));
    addTimeOfDayDescription("evening", ({
        ". The golden glow of the setting sun filters through the open windows, casting a peaceful light across the meditation gardens and the monastic halls"
        }));
    addTimeOfDayDescription("dusk", ({
        ". The shadows lengthen, and the glow of lanterns inside the temple starts to fill the air with a serene warmth as the monks prepare for their nightly rites"
        }));
    addTimeOfDayDescription("night", ({
        " silent and tranquil, with only the faint sound of chanting or the soft movements of monks meditating under the light of the moon"
        }));
    addTimeOfDayDescription("late night", ({
        " still and peaceful, the hall filled with an otherworldly quiet as the monks rest or engage in deep, solitary meditation"
        }));
    addTimeOfDayDescription("midnight", ({
        " under the pale moonlight, the monastery is peaceful and quiet, with the only movement being the monks practicing slow, deliberate movements in the courtyard"
        }));

    addSeasonDescription("winter", ({
        " with a soft blanket of snow covering the courtyard, the cold air sharp but invigorating, while the warm glow from the temple's lanterns provides a peaceful contrast"
        }));
    addSeasonDescription("spring", ({
        " with delicate flowers blooming along the pathways and the sound of gentle wind rustling through the trees in the garden"
        }));
    addSeasonDescription("summer", ({
        " with the courtyard filled with the sounds of monks performing martial arts, their movements swift and precise in the heat of the day"
        }));
    addSeasonDescription("autumn", ({
        " with the sound of rustling leaves and the scent of incense mingling in the air, the monks often meditate in the peaceful fall sunlight"
        }));

    addSourceOfLight(6, "lanterns and candles", "night");

    addDescriptionTemplate("a sacred monastery of stone and quiet discipline, home to the Fist of Aranac");
    addNearDarkDescriptionTemplate("the silhouette of a temple set against the darkening sky, lit by the soft glow of lanterns");
    addLowLightDescriptionTemplate("a tranquil stone temple surrounded by gardens and training grounds, with monks moving silently within");
    addDimLightDescriptionTemplate("an ancient monastic hall, the air filled with the scent of incense and the quiet sound of meditation");
    addSomeLightDescriptionTemplate("a peaceful monastery of stone, where monks meditate, train, and seek enlightenment under the guidance of Aranac");
}