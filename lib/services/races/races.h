//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private mapping races = ([
     "elf": ([
        "playable": 1,
        "description": "In appearance, elves typically have grey or blue eyes and blond "
            "hair. They are fair to look upon and typically stand taller than "
            "humans. In all ways, their bearing is majestic and sight of them "
            "demands attention. Elves, while they can be slain in battle or by "
            "mishap, do not age in the way that most races do - in fact, some "
            "consider them 'immortal'. The elves also tend to be aloof and "
            "somewhat detached from the outside world, seemingly only interested "
            "in their own lives. Elves also favor nature and natural beauty, "
            "their buildings and art reflect this.",
        "strength": 1,
        "intelligence": 1,
        "dexterity": 1,
        "constitution": 1,
        "charisma": 1,
        "defend attack": 1,
        "spell points": 25,
        "bonus heal spell points rate": 2,
        "skills": ([
            "elven": 8,
            "common": 5
        ]),
        "subraces": ([
            "wood elf": "woodElf.c",
            "grey elf": "greyElf.c",
            "dark elf": "darkElf.c",
            "sea elf": "seaElf.c"
        ]),
        "starting skill points": 10,
        "background trait value": 4
    ]),
    "dwarf": ([
        "playable": 1,
        "description": "The dwarves are a short, stocky race of people. They generally "
            "live in hilly or mountainous areas, usually inside caves or "
            "similar dwellings. Dwarven craftsmanship is world renowned "
            "for its durability and functionality. Dwarven structures are "
            "built to last through war and the elements. Dwarves are known for "
            "their long, braided beards, hearty appetites, and a fierce loyalty "
            "to kin and clan. They are slow to trust outsiders, but once a friend "
            "is made, that bond is unbreakable. Dwarves are also famed for their "
            "love of precious metals and gems, and many spend their lives mining "
            "the depths of the earth.",
        "strength": 1,
        "intelligence": -1,
        "wisdom": -1,
        "constitution": 2,
        "charisma": -1,
        "defense": 2,
        "stamina points": 25,
        "hit points": 25,
        "skills": ([
            "blacksmithing": 4,
            "hammer": 3,
            "dwarven": 8,
            "common": 5
        ]),
        "subraces": ([
            "Khazurathi dwarf": "khazurathiDwarf.c",
            "Mirosti dwarf": "mirostiDwarf.c"
        ]),
        "starting skill points": 8,
        "background trait value": 5
    ]),
    "draconid": ([
        "playable": 1,
        "description": "Draconids are a rare and ancient race, said to be descended from "
            "the great dragons of old. Their appearance is striking: tall and imposing, "
            "with scales that shimmer in hues of gold, bronze, or emerald. Their eyes "
            "gleam with an inner fire, and some even bear vestigial horns or crests. "
            "Draconids possess a natural affinity for magic, especially elemental forces, "
            "and are often revered or feared for their wisdom and power. Their voices "
            "carry a subtle resonance, and their presence commands respect. Legends tell "
            "of draconids who can channel the breath of dragons, though such feats are "
            "rare in the modern age.",
        "strength": 1,
        "charisma": 1,
        "intelligence": 1,
        "bonus heal spell points": 2,
        "bonus heal spell points rate": 2,
        "spell points" : 75,
        "skills": ([
            "spellcraft": 5,
            "magical essence" : 5,
            "elemental air" : 1,
            "elemental earth" : 1,
            "elemental fire" : 1,
            "elemental water" : 1,
            "draconid": 8,
            "common": 5
        ]),
        "research trees": ({ "/lib/instances/research/races/draconidResearchTree.c" }),
        "starting skill points": 8,
        "background trait value": 4
    ]),
    "maegenstryd": ([
        "playable": 1,
        "description": "The Maegenstryd are the descendants of the union of high elves, "
            "humans, and the gods themselves. It is said that Aronath - son of Aradran, "
            "the high king of the elves and Eadwyn, a goddess of hope and the mistress "
            "of desires - fell in love with Maerwena, the daughter of the human king of "
            "Tirnen. While the ensuing millenia have diluted their blood as they mate "
            "most often with humans, the touch of the gods and the elves is ever-present. "
            "In appearance, they typically have grey or blue eyes and black hair, much "
            "like their elven and human forbears did. They are typically taller than "
            "humans - few, indeed are less than six feet tall. About three thousand years "
            "ago after a great war shattered their realms to the far west, the remnants of "
            "their 'race' established the Kingdom of Eledhel and most of that land's "
            "nobility are of this race.",
        "strength": 1,
        "intelligence": 2,
        "constitution": 2,
        "charisma": 1,
        "hit points": 25,
        "spell points": 15,
        "stamina points": 15,
        "bonus heal hit points rate": 2,
        "research trees": ({ "/lib/instances/research/races/maegenstrydResearchTree.c" }),
        "skills": ([
            "ancient history": 3,
            "spellcraft": 3,
            "magical essence" : 3,
            "perception" : 1,
            "elven": 4,
            "high elven": 4,
            "eledhelean": 8,
            "common": 5
        ]),
        "starting skill points": 8,
        "background trait value": 4
    ]),
    "halfling": ([
        "playable": 1,
        "description": "Halflings are a very small people that tend to look like " 
            "miniaturized humans. The halflings are a fairly peaceful race: "
            "they don't start wars amongst themselves or others, they prefer "
            "to spend their time telling stories at gatherings... Halfling "
            "families are quite large. Halflings live in above ground homes "
            "made from materials in the surrounding forests.",
        "strength": -1,
        "charisma": -1,
        "dexterity": 2,
        "bonus heal hit points": 2,
        "bonus heal hit points rate": 2,
        "skills": ([
            "hide": 3,
            "move silently": 3,
            "common": 5
        ]),
        "starting skill points": 10,
        "background trait value": 5
    ]),
    "gnome": ([
        "playable": 1,
        "description": "The gnomes are an intelligent race of beings closely related "
            "to the dwarves. They are short, but less stocky than their "
            "dwarven cousins, They tend to have dark skin and light colored "
            "hair and are well-known for their rather large noses. The gnomes "
            "are a playful race, and they love to play jokes on others. "
            "They generally reside in tunnels burrowed into mountains or "
            "hills.",
        "strength": -1,
        "wisdom": -1,
        "intelligence": 2,
        "spell points": 25,
        "bonus heal spell points": 2,
        "skills": ([
            "spellcraft": 3,
            "engineering": 2,
            "common": 8
        ]),
        "starting skill points": 10,
        "background trait value": 5
    ]),
    "half elf": ([
        "playable": 1,
        "description": "Half-elves are the rare offspring of unions between elves and humans. "
            "They inherit the beauty, grace, and keen senses of their elven heritage, as well "
            "as the adaptability and ambition of humankind. In appearance, half-elves are "
            "often tall and fair, with features that blend the best of both lineages with eyes that seem to "
            "hold both wisdom and longing. Caught between two worlds, half-elves are often marked by a sense of "
            "melancholy and a longing for belonging, for they are not fully accepted by either elves or men. In legend, "
            "some half-elves have been given the choice of mortality or immortality, a burden and a gift that shapes "
            "their destinies.",
        "intelligence": 1,
        "hit points": 10,
        "spell points": 25,
        "skills": ([
            "spellcraft": 3,
            "elven": 8,
            "common": 8
        ]),
        "starting skill points": 10,
        "background trait value": 5
    ]),
    "half orc": ([
        "playable": 1,
        "description": "Half-orcs are people that have both human and orcish parents. " 
            "Like most crossbreeds, they are shunned by both of their races, " 
            "they gain the physical strength of their orcish heritage, along " 
            "with the incredible stamina of the orcs. From their human side, " 
            "they gain intelligence and dexterity that the orcs lack.",
        "strength": 2,
        "constitution": 1,
        "intelligence": -1,
        "charisma": -2,
        "stamina points": 50,
        "spell points": -50,
        "skills": ([
            "orcish": 8
        ]),
        "starting skill points": 8,
        "background trait value": 5
    ]),
    "faerie": ([
        "playable": 1,
        "description": "The faeries are a magical race of winged humanoids. They are " 
            "smaller than humans, and are generally friendly to all. The "
            "faeries enjoy conversation, and enjoy companionship. They "
            "tend to have their own personal agendas, that they keep to "
            "themselves, faeries like secrets. The faeries tend to reside "
            "in forests or prairies, though they hide their existence well.",
        "strength": -2,
        "dexterity": 2,
        "constitution": -2,
        "charisma": 1,
        "intelligence": 1,
        "bonus heal spell points": 2,
        "bonus heal spell points rate": 4,
        "spell points": 50,
        "hit points": -50,
        "skills": ([
            "spellcraft": 5,
            "magical essence" : 5,
            "elven": 8,
            "common": 8
        ]),
        "starting skill points": 10,
        "background trait value": 5
    ]),
    "human": ([
        "playable": 1,
        "description": "Humans are the most common race. They don't have any "
            "real preferences on where they live, except that they prefer tropical "
            "or temperate regions. They live in above ground dwellings, and tend "
            "to admire the elaborate, elegant architecture of the elves and dwarves. "
            "Humans gain no advantages or disadvantages on RealmsMUD, they are the "
            "happy medium... and they like it that way.",
        "subraces": ([
            "Eledhelean": "eledhelHuman.c",
            "Hillgarathi": "hillgarathHuman.c",
            "Tirnosti": "tirnostHuman.c",
            "Menadrosti": "menadrostHuman.c",
            "Iarwathean": "iarwathHuman.c",
            "Helcarish": "helcarionHuman.c",
            "Celebnosti": "celebnostHuman.c",
            "Andurathi": "andurathHuman.c",
            "Linmiri": "linmirHuman.c",
            "Endurgish": "endurghulHuman.c",
            "Zhenduli": "zhendulachHuman.c"
        ]),
        "skills": ([
            "common": 5
        ]),
        "starting skill points": 14,
        "background trait value": 6
    ]),
    "half troll": ([
        "playable": 1,
        "description": "Half-trolls are people that have both human and troll parents. "
            "Half trolls are often seen by other trolls in much the same light as "
            "pure-blood trolls - trolls simply don't seem to care if half-trolls "
            "have a human parent. Half-trolls generally live with trolls, which "
            "is wherever they feel like living.",
        "strength": 5,
        "constitution": 2,
        "dexterity": -1,
        "wisdom": -1,
        "intelligence": -1,
        "charisma": -2,
        "bonus heal hit points": 2,
        "bonus heal hit points rate": 4,
        "bonus heal spell points rate": -4,        
        "spell points": -100,
        "hit points": 100,
        "stamina points": 25,
        "defense": 4,
        "skills": ([
            "orcish": 8
        ]),
        "starting skill points": 6,
        "background trait value": 5
    ]),
    "high elf": ([
        "playable": 1,
        "description": "In the crafting of items of wonder, in strength, in keen intelligence, "
            "and in the learning of knowledge, few surpass the high elves. Indeed, "
            "written language was first used by them. Industrious, no other race did "
            "more to beautify the lands of the world. So honored were they that the once "
            "lived with the very gods of the world. Little is here recorded of their deeds "
            "in those times save that many high elves left the blessed lands on the heels "
            "of a great enemy and that a darkness, both of deeds and of the soul, enshrouds "
            "them. In appearance, high elves typically have grey or blue eyes and black hair. "
            "They are fair to look upon and stand nigh on 7 feet tall. In all ways, their "
            "bearing is majestic and sight of them demands attention.",
        "strength": 1,
        "intelligence": 2,
        "constitution": 1,
        "charisma": 2,
        "defend attack": 1,
        "hit points": 25,
        "spell points": 50,
        "bonus heal spell points rate": 2,
        "research trees": ({ "/lib/instances/research/races/highElfResearchTree.c" }),
        "skills": ([
            "spellcraft": 5,
            "blacksmithing": 3,
            "weapon smithing": 3,
            "long sword": 5,
            "bow": 3,
            "elven": 8,
            "high elven": 10,
            "common": 8
        ]),
        "subraces": ([
            "Half elf": "deityTouchedElf.c",
            "Hillgarathi elf": "hillgarathElf.c",
            "moon elf": "echorluinElf.c"
        ]),
        "starting skill points": 6,
        "background trait value": 4
    ]),
    "catfolk": ([
        "playable": 0,
        "description": "Catfolk are a lithe, agile race with feline features - slitted eyes, "
            "tufted ears, and tails. Their bodies are covered in soft fur, patterned in "
            "stripes or spots, and their movements are graceful and silent. Catfolk are "
            "known for their keen senses, quick reflexes, and a natural curiosity that "
            "sometimes gets them into trouble. They often live in close-knit tribes or "
            "roam as solitary wanderers, preferring warm climates and dense forests. "
            "Catfolk are playful and clever, but can be fiercely territorial when threatened.",
        "dexterity": 2,
        "stamina points": -25,
        "spell points": 25,
        "skills": ([
            "common":8
        ]),
        "starting skill points": 14,
        "background trait value": 6
    ]),
    "orc": ([
        "playable": 0,
        "description": "Orcs are a brutish, warlike race, known for their great strength and "
            "endurance. Their skin ranges from deep green to gray, and their faces are "
            "marked by prominent tusks and heavy brows. Orcs live in tribal societies, "
            "often in harsh, unforgiving lands. They value strength, courage, and loyalty "
            "to their clan above all else. While often seen as savage by outsiders, orcs "
            "have a rich oral tradition and a deep respect for their ancestors. Their "
            "society is harsh, but not without honor.",
        "strength": 2,
        "constitution": 2,
        "intelligence": -2,
        "charisma": -4,
        "stamina points": 50,
        "spell points": -50,
        "skills": ([
            "orcish": 8
        ]),
        "starting skill points": 8,
        "background trait value": 5
    ]),
    "troll": ([
        "playable": 0,
        "description": "Trolls are towering, monstrous humanoids, often standing over ten feet "
            "tall. Their skin is thick and leathery, ranging from mossy green to stone gray, "
            "and their bodies are powerfully built. Trolls are infamous for their regenerative "
            "abilities, able to recover from wounds that would kill most creatures. They are "
            "notoriously difficult to kill, and their tempers are as legendary as their "
            "appetites. Trolls dwell in caves, swamps, or mountains, and are feared by most "
            "other races for their strength and ferocity.",
        "strength": 8,
        "constitution": 4,
        "dexterity": -4,
        "wisdom": -4,
        "intelligence": -4,
        "charisma": -4,
        "bonus heal hit points": 4,
        "bonus heal hit points rate": 8,
        "bonus heal spell points rate": -8,        
        "heal hit points": 4,
        "heal hit points rate": 8,
        "heal spell points rate": -8,  
        "spell points": -200,
        "hit points": 100,
        "resist fire": -50,
        "stamina points": 25,
        "defense": 4,
        "skills": ([
            "orcish": 8
        ]),
        "starting skill points": 6,
        "background trait value": 5
    ]),
    "gnoll": ([
        "playable": 0,
        "description": "Gnolls are hyena-like humanoids, tall and lean with mottled fur and "
            "a predatory grin. They are known for their savagery and pack mentality, "
            "often raiding settlements and caravans. Gnolls are driven by hunger and "
            "a desire for dominance, and their society is ruled by the strongest. "
            "Despite their fearsome reputation, gnolls are cunning hunters and "
            "skilled trackers, able to survive in the harshest environments.",
        "strength": 2,
        "intelligence": -2,
        "charisma": -4,
        "stamina points": 25,
        "spell points": -50,
        "skills": ([
            "orcish": 8
        ]),
        "starting skill points": 8,
        "background trait value": 5
    ]),
    "fuin-nedesar": ([
        "playable": 0,
        "description": "The Fuin-nedesar are a mysterious race that have just recently appeared. "
            "Standing nearly eight feet tall, their forms are imposing and reminiscent of living gargoyles, "
            "with stony, angular features and powerful, talon-tipped limbs. Their skin seems to shimmer "
            "with an inner light, often tinged with blue or silver, and their eyes glow with the power of "
            "the storm. Fuin-nedesar are said to be descended from beings of pure magic. They are masters "
            "of elemental air, able to call lightning and ride the winds. Rarely seen, they prefer to dwell "
            "in hidden valleys or atop storm-lashed peaks.",
        "strength": 4,
        "constitution": 2,
        "intelligence": 2,
        "charisma": -4,
        "defend attack": 1,
        "resist electricity": 75,
        "attacks": ([
            "electricity": 15,
        ]),
        "skills": ([
            "spellcraft": 5,
            "elemental air": 5,
        ]),
        "stamina points": 50,
        "spell points": -50,
        "skills": ([
            "orcish": 10,
            "elvish": 8,
            "common": 10
        ]),
        "starting skill points": 8,
        "background trait value": 5
    ]),
    "giant": ([
        "playable": 0,
        "description": "Giants are massive humanoids, towering over all other races. Their "
            "skin is as tough as stone, and their strength is legendary. Giants live in "
            "remote mountains or highlands, often in great halls carved from the living "
            "rock. They are slow to anger but unstoppable when roused. Giants have a "
            "deep connection to the land, and their traditions are ancient, passed down "
            "through epic tales and songs.",
        "strength": 10,
        "constitution": 6,
        "intelligence": -4,
        "dexterity": -4,
        "charisma": -4,
        "defense": 10,
        "hit points": 50,
        "stamina points": 50,
        "spell points": -50,
        "skills": ([
            "orcish": 8
        ]),
        "starting skill points": 8,
        "background trait value": 5
    ]),
    "goblin": ([
        "playable": 0,
        "description": "Goblins are small, wiry humanoids with green or gray skin, sharp "
            "features, and large, expressive eyes. They are known for their cunning, "
            "resourcefulness, and love of mischief. Goblins live in sprawling underground "
            "lairs or in the shadows of larger orcish tribes. Though physically weak, "
            "they make up for it with numbers and clever traps. Goblins are quick to "
            "flee when outmatched, but can be dangerous in large groups.",
        "strength": 2,
        "constitution": 1,
        "intelligence": -2,
        "charisma": -4,
        "stamina points": 50,
        "spell points": -50,
        "skills": ([
            "orcish": 8
        ]),
        "starting skill points": 8,
        "background trait value": 5
    ]),
    "ogre": ([
        "playable": 0,
        "description": "Ogres are hulking brutes, larger than orcs but smaller than giants. "
            "Their skin is thick and often covered in warts or scars, and their faces are "
            "marked by heavy jaws and protruding tusks. Ogres are feared for their "
            "strength and appetite for destruction. They live in crude camps or caves, "
            "raiding nearby settlements for food and loot. Despite their fearsome "
            "appearance, ogres are not without a crude sense of humor and a love of "
            "simple pleasures.",
        "strength": 6,
        "constitution": 2,
        "dexterity": -1,
        "intelligence": -2,
        "charisma": -4,
        "hit points": 100,
        "stamina points": 100,
        "spell points": -50,
        "skills": ([
            "orcish": 8
        ]),
        "starting skill points": 8,
        "background trait value": 5
    ]),
    "centaur": ([
        "playable": 0,
        "description": "Centaurs are a noble race with the upper body of a human and the "
            "lower body of a horse. They are swift and powerful, able to cover great "
            "distances with ease. Centaurs dwell in forests and plains, living in "
            "close-knit herds. They are known for their wisdom, love of music and poetry, "
            "and skill with the bow. Centaurs value freedom and the open sky above all else.",
        "strength": 2,
        "constitution": 2,
        "dexterity": -2,
        "stamina points": 100,
        "skills": ([
            "common": 8
        ]),
        "starting skill points": 8,
        "background trait value": 5
    ]),
    "bugbear": ([
        "playable": 0,
        "description": "Bugbears are large, hairy goblinoids, standing taller than most orcs. "
            "Their fur is thick and matted, and their faces are twisted into perpetual "
            "scowls. Bugbears are stealthy for their size, able to move quietly despite "
            "their bulk. They are feared as ambushers and assassins, often serving as "
            "enforcers in goblin or orcish tribes. Bugbears respect strength and cunning "
            "above all else.",
        "strength": 2,
        "constitution": 1,
        "intelligence": -2,
        "charisma": -4,
        "stamina points": 50,
        "spell points": -50,
        "skills": ([
            "orcish": 8
        ]),
        "starting skill points": 8,
        "background trait value": 5
    ]),
    "dryad": ([
        "playable": 0,
        "description": "Dryads are mystical tree spirits, appearing as beautiful humanoids "
            "with bark-like skin and hair of leaves or blossoms. They are deeply connected "
            "to the forests they inhabit, able to move through trees and command the "
            "forces of nature. Dryads are gentle and elusive, rarely seen by mortals. "
            "They are protectors of the wild, and their wrath is terrible when their "
            "groves are threatened.",
        "strength": 2,
        "constitution": -1,
        "intelligence": 2,
        "charisma": 2,
        "hit points": -25,
        "spell points": 150,
        "skills": ([
            "common": 8,
            "elven": 8
        ]),
        "starting skill points": 8,
        "background trait value": 5
    ]),
    "vairaug": ([
        "playable": 0,
        "description": "Vairaug are an ancient and enigmatic race, said to be the children "
            "of fire and magic. Their forms are tall and regal, with skin that glows "
            "like embers and eyes that burn with inner light. Vairaug are masters of "
            "arcane arts, able to command elemental forces with ease. They are rarely "
            "seen outside their hidden enclaves, and their motives are inscrutable to "
            "other races. Legends speak of their role in shaping the world in ages past.",
        "strength": 6,
        "constitution": 6,
        "intelligence": 6,
        "defense": 8,
        "stamina points": 150,
        "spell points": 250,
        "resist fire": 50,
        "skills": ([
            "common": 8,
            "elven": 8,
            "high elven": 8,
            "spellcraft": 8,
            "magical essence": 5,
            "elemental fire": 10,
        ]),
        "starting skill points": 12,
        "background trait value": 6
    ]),
    "changeling": ([
        "playable": 0,
        "description": "Changelings are shapeshifters, able to alter their appearance at will. "
            "Their true form is rarely seen, but is said to be androgynous and unremarkable. "
            "Changelings are masters of disguise and deception, able to blend into any society. "
            "They are often mistrusted by other races, but their talents make them invaluable "
            "as spies and infiltrators. Changelings value adaptability and cunning above all else.",
        "intelligence": 2,
        "stamina points": 50,
        "spell points": -50,
        "skills": ([
            "common": 8,
            "spellcraft": 8,
            "senses": 6,
            "body": 6,
        ]),
        "starting skill points": 8,
        "background trait value": 5
    ]),
    "hobgoblin": ([
        "playable": 0,
        "description": "Hobgoblins are larger and more disciplined cousins of goblins. "
            "They are known for their martial prowess, strict hierarchies, and "
            "well-organized warbands. Hobgoblins have reddish or dark brown skin, "
            "and their faces are marked by sharp features and fierce eyes. They "
            "value order, strength, and loyalty to their leaders. Hobgoblins are "
            "respected and feared by other goblinoids.",
        "strength": 3,
        "constitution": 2,
        "intelligence": -2,
        "charisma": -4,
        "stamina points": 50,
        "spell points": -50,
        "skills": ([
            "orcish": 8
        ]),
        "starting skill points": 8,
        "background trait value": 5
    ]),
    "kobold": ([
        "playable": 0,
        "description": "Kobolds are small, reptilian humanoids with scaly skin and "
            "dog-like faces. They are clever and resourceful, known for their "
            "traps and ambushes. Kobolds live in underground warrens, rarely "
            "venturing to the surface. They are fiercely territorial and "
            "often serve as minions to dragons or other powerful creatures. "
            "Despite their size, kobolds are brave in large numbers.",
        "strength": -1,
        "dexterity": 2,
        "constitution": 1,
        "intelligence": -1,
        "charisma": -2,
        "stamina points": 50,
        "spell points": -50,
        "skills": ([
            "orcish": 8
        ]),
        "starting skill points": 8,
        "background trait value": 5
    ]),
    "minotaur": ([
        "playable": 0,
        "description": "Minotaurs are powerful, bull-headed humanoids, known for their "
            "strength and ferocity in battle. Their bodies are covered in short fur, "
            "and their heads are crowned with great horns. Minotaurs are often found "
            "in labyrinthine lairs, where their sense of direction is unmatched. "
            "They are proud and stubborn, but value honor and personal strength.",
        "strength": 4,
        "constitution": 2,
        "intelligence": -2,
        "charisma": -2,
        "hit points": 25,
        "stamina points": 100,
        "spell points": -50,
        "skills": ([
            "common": 8
        ]),
        "starting skill points": 16,
        "background trait value": 5
    ]),
    "satyr": ([
        "playable": 0,
        "description": "Satyrs are woodland spirits with the upper body of a human and the "
            "lower body of a goat. They are known for their love of music, dance, and "
            "revelry. Satyrs are mischievous and free-spirited, often leading travelers "
            "astray for their own amusement. Despite their playful nature, satyrs are "
            "wise in the ways of the wild and possess potent magical abilities.",
        "intelligence": 1,
        "charisma": 2,
        "spell points": 50,
        "skills": ([
            "spellcraft": 8
        ]),
        "starting skill points": 8,
        "background trait value": 5
    ]),
    "deity": ([
        "playable": 0,
        "description": "Deities are beings of immense power, worshipped by mortals as gods. "
            "Their forms are as varied as their domains, but all radiate an aura of "
            "majesty and authority. Deities command the forces of creation and destruction, "
            "and their will shapes the fate of the world. Few mortals ever encounter a "
            "deity, and those who do are forever changed by the experience.",
        "strength": 6,
        "constitution": 6,
        "intelligence": 6,
        "defense": 8,
        "stamina points": 150,
        "spell points": 250,
        "resist fire": 25,
        "resist earth": 25,
        "resist air": 25,
        "resist water": 25,
        "resist magical": 25,
        "resist energy": 25,
        "skills": ([
            "common": 8,
            "elven": 8,
            "high elven": 8,
            "spellcraft": 12,
            "magical essence": 12,
        ]),
        "starting skill points": 12,
        "background trait value": 6

    ]),
    "lizardfolk": ([
        "playable": 0,
        "description": "Lizardfolk are reptilian humanoids, with scaly hides and long, "
            "powerful tails. They are well adapted to swampy or marshy environments, "
            "able to swim with ease and breathe underwater for short periods. "
            "Lizardfolk are stoic and pragmatic, valuing survival and the strength "
            "of the tribe above all else. Their society is organized around the "
            "strongest and most cunning leaders.",
        "strength": 2,
        "constitution": 2,
        "intelligence": -2,
        "charisma": -4,
        "stamina points": 50,
        "spell points": -50,
        "skills": ([
            "common": 6
        ]),
        "starting skill points": 12,
        "background trait value": 5
    ]),
]);
