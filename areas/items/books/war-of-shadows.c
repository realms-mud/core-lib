//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights
// reserved. See the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "The War of Shadows");
    set("short", "A book titled 'The War of Shadows'");
    set("title", "The War of Shadows: The Vale Under Siege");
    set("aliases", ({ "war of shadows", "vale siege", "kharand war",
        "northern chronicles", "book" }));
    set("long", "The uneasy peace in the Vale shattered as Kharand struck "
        "openly. Undead and orcish forces moved with cunning and cruelty. "
        "Hillgarath and Eledhel rallied their knights and dwarves for war, "
        "facing horrors beyond mortal comprehension. This volume follows "
        "battles, strategies, and the courage of those who dared confront "
        "the darkness.");

    addChapter("Chapter 1: The First Strike",
        "The alarm bell rang through Hillgarath at first light.\n"
        "Scouts had returned with news of burning villages to the north.\n"
        "Orcish raiders, led by dark spellcasters, swept through the\n"
        "forests. Beren and Areladur convened the council, urgency in every\n"
        "word. Villagers fled, abandoning homes, livestock, and hopes\n"
        "alike. Knights mounted quickly, armor clanging, swords at the\n"
        "ready. Dwarves fortified gates, chanting wards over walls and\n"
        "towers. The air smelled of smoke, iron, and fear, thick and\n"
        "clinging. Reports spoke of undead among the raiders, bodies\n"
        "moving unnaturally. Areladur rode with a company to meet the\n"
        "enemy along the ridge. Beren led another, flanking the orcs\n"
        "before they could advance further. Arrows and spells flew, fire\n"
        "clashing against darkness in the hills. Some corpses rose after\n"
        "falling, animated by dark, unseen magic. The first battle tested\n"
        "courage, and the Vale felt its weight. When night fell, watchfires\n"
        "burned on the ridges, unextinguished. Patrols reported shadows\n"
        "moving outside the light, silent and patient. Even victorious, the\n"
        "defenders knew this war would be long. The northern threat was no\n"
        "longer subtle; it was immediate. Fear mingled with resolve,\n"
        "shaping every plan and every stride. Hillgarath braced itself,\n"
        "aware that each dawn might bring death.");

    addChapter("Chapter 2: March of the Damned",
        "Undead rose in the passes, a plague upon the mountains.\n"
        "Villagers spoke of figures walking without breath or sound.\n"
        "Knights rode into the hills, their banners snapping in icy\n"
        "wind. Dwarves lit ward fires, chanting, hammering glyphs into\n"
        "stone. Areladur documented every movement, every unnatural\n"
        "sign. Beren commanded flanks, ensuring villagers could retreat\n"
        "safely. Corpses attacked with relentless force, hunger in hollow\n"
        "eyes. Spells and steel met fleshless foes, yet they came again.\n"
        "The alliance gathered reinforcements, calling distant allies.\n"
        "Each village became a fortress, each forest a trap-filled maze.\n"
        "Scouts reported strange markings burned into trees and rocks.\n"
        "Some whispered of Kharand's sorcery, old and deep in its power.\n"
        "Even the dwarves admitted unease, for magic beyond their runes\n"
        "stirred. Areladur's journal recorded fear, courage, hope, and\n"
        "despair. Nights were spent watching, arrows nocked, spells at the\n"
        "ready. Villagers slept in shifts, every shadow a potential\n"
        "enemy. The Vale learned that war was not only of men, but of\n"
        "spirits. Every victory was tempered by loss, every rest shadowed\n"
        "by dread. The alliance endured, knowing the north demanded\n"
        "vigilance. And still, Kharand's forces moved, patient, cunning,\n"
        "and relentless.");

    addChapter("Chapter 3: Siege of Linmir",
        "Linmir, a town on the edge of the Vale, became the next target.\n"
        "Flames licked the sky as the enemy approached under dark\n"
        "banners. Beren led the defense, knights in shining armor against\n"
        "shadowed foes. Dwarves reinforced the walls, setting traps and\n"
        "wards along the gates. Corpses walked the streets before the\n"
        "living could mount resistance. Arrows flew and spells shattered\n"
        "the night with bright flashes. The townsfolk fought alongside\n"
        "soldiers, every hand a weapon. Some were taken by fear, others\n"
        "by the undead that walked. Areladur directed counterattacks,\n"
        "rallying men from every quarter. Despite loss, Linmir held,\n"
        "though the cost was grave and bitter. Smoke rose over the town,\n"
        "obscuring bodies, both dead and undead. The defenders prayed to\n"
        "the old gods, and their chants held the night. Beren noted in his\n"
        "journal that courage could not conquer despair alone.\n"
        "Reinforcements arrived at dawn, turning the tide with fresh\n"
        "strength. The siege lifted, but the scars remained in the hearts\n"
        "of all. Messages flew to other towns, warning of Kharand's\n"
        "growing power. Villagers rebuilt as best they could, but fear\n"
        "lingered like a shadow. The northern army had tested the Vale,\n"
        "revealing its strength and limits. Victory was hard-won, but the\n"
        "war was far from over. Each day, Kharand's shadow grew, and the\n"
        "defenders steeled themselves.");

    addChapter("Chapter 4: Allies and Intrigue",
        "As battles raged, spies and scouts moved across the Vale. Some\n"
        "were loyal, others deceived, carrying false tidings. Dwarves\n"
        "spoke of hidden passages beneath the mountains. Beren dispatched\n"
        "envoys to distant lands, seeking allies anew. Areladur tracked\n"
        "movements of Kharand's generals with care. Night brought whispered\n"
        "councils and secret plots uncovered. Villagers learned to\n"
        "recognize signs of deception and disguise. Dwarves shared old\n"
        "songs that revealed traps and ambushes. The alliance forged\n"
        "plans, balancing offense and careful defense. Kharand's forces\n"
        "tested them at every turn, probing weaknesses. Some knights fell\n"
        "to treachery, others discovered hidden strengths. Areladur\n"
        "recorded each event in detail, for the chronicles must remain.\n"
        "Messages carried across mountain passes warned of approaching\n"
        "doom. Every spy report revealed Kharand's cunning and the scope\n"
        "of threat. Beren strengthened the northern garrison, preparing\n"
        "for new assaults. The Vale was alive with tension, hope, fear,\n"
        "and fierce resolve. Villagers and soldiers alike learned the\n"
        "weight of living under siege. Alliances deepened, forged in fire\n"
        "and necessity, but fragile still. Kharand watched and waited,\n"
        "unseen yet palpably present. The war of shadows had only begun,\n"
        "and none could yet see its end.");
}
