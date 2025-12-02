//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("courtyard");

    addAdjectives(({
        "wide-open area surrounded by weathered stone walls with patches of grass struggling through the cobblestones",
        "small courtyard where faded banners hang limply from rusted brackets",
        "castle courtyard with cracked flagstones and a dry, weathered well at its center",
        "quiet inner yard where creeping ivy has reclaimed much of the ancient stonework",
        "walled garden where the remnants of ornamental bushes grow wild among the stones",
        "sheltered courtyard where the elements have eroded intricate stone carvings over centuries",
        "castle yard where training dummies stand forgotten, slowly rotting in the elements",
        "secluded courtyard with a crumbling stone bench beneath a gnarled old tree",
        "central yard where rainwater has pooled in the depressions of worn flagstones",
        "wide-open space enclosed by high walls with arrow slits and defensive parapets",
        "modest courtyard where the foundations of former structures create uneven ground",
        "inner bailey where the weathered remains of a sundial marks the passage of time",
        "walled garden where hardy weeds now grow between decorative stonework",
        "sheltered space where the shadows of surrounding towers create cooling shade",
        "castle courtyard where moss and lichen paint the ancient stones in mottled greens",
        "quiet yard where fallen leaves accumulate in the corners, rustling in the breeze",
        "open area where the occasional wildflower adds splashes of color to the gray stones",
        "inner courtyard where a partially collapsed fountain stands as a monument to better days",
        "walled yard where the claw marks of time have sculpted the surrounding stonework",
        "castle courtyard where birds nest in the crevices of the surrounding structures"
        }));

    addDescriptionTemplate("a ##Adjective##");

    addNearDarkDescriptionTemplate(
        "a shadowy courtyard where only the outlines of surrounding walls and structures "
        "are visible. The open sky above offers little illumination, leaving the yard "
        "as a dark void enclosed by deeper darkness"
    );

    addLowLightDescriptionTemplate(
        "a dimly lit courtyard where the surrounding walls loom as dark silhouettes. "
        "Underfoot, the uneven surface of flagstones presents a hazard in the poor light, "
        "while the open sky above provides minimal illumination"
    );

    addDimLightDescriptionTemplate(
        "a partially illuminated ##Adjective##, where shadows pool in corners and recesses "
        "of the stonework. The subtle interplay of light and shadow highlights the age and "
        "weathering of this once grand space"
    );

    addSomeLightDescriptionTemplate(
        "a well-lit ##Adjective##. Whether under the bright sun or moonlight, the "
        "full character of the courtyard is revealed - from the worn paths crossing "
        "its expanse to the weather-beaten walls that have stood guard for generations"
    );

    // Time of day modifiers with 6+ variations
    addTimeOfDayDescription("dawn", ({
        ". The first rays of sunlight touch the tops of the walls, while much of the courtyard still lies in cool shadow",
        ". Dew glistens on sparse patches of grass as the morning light slowly creeps across the flagstones",
        ". Birds call from nesting places in the surrounding walls, greeting the day's first light",
        ". A gentle mist hovers just above the ground, slowly burning away as sunlight strengthens",
        ". Long shadows stretch across the yard, making the worn carvings in the stone walls seem deeper and more mysterious",
        ". The cool morning air carries the scent of stone and earth as the courtyard awakens from darkness"
        }));

    addTimeOfDayDescription("morning", ({
        ". Angled morning light streams between the towers, creating stark patterns of light and shadow on the ancient stones",
        ". The warming stones release the night's dampness as steam that rises in thin wisps from the courtyard floor",
        ". The surrounding walls seem less intimidating in the clear light of morning, their imperfections more apparent",
        ". Small creatures scurry along the base of the walls, seeking shelter from the increasing light",
        ". The morning light reveals details lost in darkness - faded heraldic designs etched into cornerstone blocks",
        ". Spider webs strung between forgotten brackets glitter with moisture in the strengthening sunlight"
        }));

    addTimeOfDayDescription("noon", ({
        ". The sun stands directly overhead, minimizing shadows and revealing the full extent of the weathered flagstones",
        ". Heat radiates from the stone surfaces, creating rippling air above the courtyard floor",
        ". The harsh overhead light bleaches color from the courtyard, leaving it in stark contrasts of light and dark",
        ". No shade can be found except directly against the base of the walls, where creatures and plants seek refuge",
        ". The courtyard seems smaller under the direct sun, with every crack and weathered stone exposed to view",
        ". The stillness of midday hangs over the space, with even the birds falling silent in the heat"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". Lengthening shadows stretch across the yard as the sun begins its descent, highlighting the textures of the worn surfaces",
        ". The western walls begin to glow with warm light while the eastern side falls into cooling shadow",
        ". The angle of light reveals ancient mason marks and inscriptions normally hidden in the stonework",
        ". Dust motes dance in slanting beams of sunlight that pierce between the crenellations above",
        ". The shadows of the surrounding towers slowly creep across the courtyard like the hands of a giant sundial",
        ". The stones release the day's accumulated heat, creating a pleasant warmth in the cooling air"
        }));

    addTimeOfDayDescription("evening", ({
        ". The golden light of evening warms the cold stones briefly before the shadows deepen with approaching night",
        ". Long shadows stretch completely across the courtyard, merging together as the light fades",
        ". The last direct sunlight catches only the highest western-facing stones, turning them briefly to gold",
        ". The courtyard slowly transitions from day's clarity to evening's mystery as details soften in the fading light",
        ". Birds return to roost in the crevices of the surrounding walls as night approaches",
        ". The evening air cools rapidly, drawing out scents of stone and earth that were suppressed by day's heat"
        }));

    addTimeOfDayDescription("dusk", ({
        ". The fading light casts the courtyard in shades of blue and purple as darkness claims the corners and recesses",
        ". Stars begin to appear overhead while the courtyard floor remains visible in the last ambient light",
        ". Bats emerge from hidden crevices in the walls, flitting across the darkening sky above the open space",
        ". The transition between stone walls and sky blurs as light fades, making the courtyard seem both smaller and more open",
        ". Forms lose their definition, with only the palest stones still catching enough light to stand out from shadow",
        ". The day's heat dissipates quickly from the stones, leaving a chill that rises from the ground"
        }));

    addTimeOfDayDescription("night", ({
        ". Moonlight bathes the open space in silver, creating a stark beauty from the crumbling architecture",
        ". Stars wheel overhead, their light barely illuminating the dark stone underfoot",
        ". The courtyard becomes a well of darkness surrounded by the slightly lighter silhouettes of walls against the night sky",
        ". Nocturnal creatures rustle in shadowed corners, their movements betrayed only by occasional sounds",
        ". The ambient starlight casts no true shadows, leaving the yard in uniform darkness broken only by the palest stones",
        ". The outlines of the walls seem to waver and shift as clouds occasionally obscure the night sky"
        }));

    // Season modifiers with 6+ variations
    addSeasonDescription("winter", ({
        " covered with patches of snow, the white blanket temporarily hiding the ravages of time on the stones beneath",
        " with frost rimming the edges of stones and glittering in the mortar joins between blocks",
        " where bare tree branches cast intricate shadow patterns across the snow-dusted ground",
        " exposed to bitter winds that whistle through arrow slits and abandoned crenellations",
        " with ice forming in depressions where water has pooled, cracking the stone further with each freeze",
        " silent and still, the harsh winter having driven even the hardiest creatures to seek warmer shelter",
        " where snow has drifted against the north-facing walls, piling high against the ancient stonework"
        }));

    addSeasonDescription("spring", ({
        " showing signs of renewal, with small flowers and fresh green shoots emerging between cracks in the ancient stonework",
        " becoming a haven for nesting birds who return to familiar crevices in the surrounding walls",
        " where rainwater pools in shallow depressions, reflecting the changing skies above",
        " with the first tender growth pushing through winter's decay, adding spots of color to the gray stone",
        " freshened by spring rains that wash away winter's grime, revealing forgotten details in the weathered stone",
        " alive with insects buzzing between the newly-sprouted wildflowers that have colonized the courtyard floor",
        " where pale green moss spreads across damp stones, softening the harsh lines of the architecture"
        }));

    addSeasonDescription("summer", ({
        " baking under the summer sun, the stones radiating heat while sparse patches of hardy grass wither at the edges",
        " with lizards basking on sun-warmed stones, disappearing into cracks at the slightest movement",
        " where the dry heat has concentrated the scent of stone, dust, and the sparse herbs growing between flagstones",
        " offering brief respite from the sun in the shadows of its high surrounding walls",
        " with wildflowers stubbornly blooming in corners where rainwater occasionally collects",
        " where the contrast between blazing sunlight and deep shadow makes the courtyard seem divided into two worlds",
        " quiet during the hottest hours, coming alive again with insect and bird activity as evening approaches"
        }));

    addSeasonDescription("autumn", ({
        " scattered with fallen leaves blown in from beyond the walls, adding splashes of gold and russet to the gray stone",
        " where early morning frost outlines fallen leaves before melting away under the strengthening sun",
        " with seed heads of tall grasses nodding in the breeze that sweeps across the open space",
        " growing damper as autumn rains seep into the porous stone, darkening the courtyard floor",
        " where ivy clinging to the walls turns crimson and gold before eventually withering",
        " smelling of damp stone and vegetative decay as summer's growth surrenders to the changing season",
        " where migrating birds briefly rest on the walls before continuing their journey southward"
        }));

    useExteriorLighting();
}
