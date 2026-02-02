//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private nosave mapping creatureBlueprints = ([
    "basilisk":([
        "description": "The basilisk is a legendary serpent-like creature, famed for its "
            "deadly gaze and venomous fangs. Its scales shimmer with a sickly green "
            "hue, and its eyes burn with an unnatural intensity. Legends say that a "
            "single glance from a basilisk can turn the unwary to stone, and its very "
            "presence is enough to inspire terror in even the bravest adventurers. "
            "It moves with a slow, sinuous grace, and its lair is often littered with "
            "the petrified remains of its victims.",
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 15,
        "attacks": ([
            "fangs": 15,
        ]),
        "special attacks": ([
            "poison": 25,
            "paralysis": 10,
        ]),
        "base hit points": 150,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "bat":([
        "description": "Bats are small, nocturnal mammals with leathery wings and keen "
            "hearing. They flit silently through the night, using echolocation to "
            "navigate and hunt for insects. While most bats are harmless, some "
            "species can be aggressive if threatened, using their sharp fangs and "
            "claws to defend themselves. In dark caves and ancient ruins, swarms of "
            "bats can become a formidable nuisance.",
        "category": "animal",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 1,
        "maximum level": 5,
        "attacks": ([
            "claw": 3,
            "claw": 3,
            "fangs": 5,
        ]),
        "base hit points": 10,
        "base spell points" : 0,
        "base stamina points" : 50
    ]),
    "black bear":([
        "description": "The black bear is a powerful and imposing animal, covered in thick, "
            "dark fur. It is known for its strength and surprising agility, able to "
            "climb trees and swim with ease. Black bears are generally solitary, "
            "roaming forests in search of berries, fish, and small game. When "
            "provoked or defending their young, they can become fearsome opponents, "
            "striking with massive claws and powerful jaws.",
        "category": "animal",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "bear" }),
        "minimum level": 10,
        "maximum level": 25,
        "attacks": ([
            "claw": 10,
            "claw": 10,
            "fangs": 15,
        ]),
        "base hit points": 150,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "brown bear":([
        "description": "Brown bears are among the largest land predators, with a massive "
            "frame and a thick coat of brown fur. They are formidable hunters and "
            "scavengers, capable of taking down large prey or defending themselves "
            "against multiple attackers. Brown bears are known for their strength, "
            "endurance, and ferocity when threatened. In the wild, they are both "
            "respected and feared by all who share their territory.",
        "category": "animal",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "bear" }),
        "minimum level": 15,
        "maximum level": 35,
        "attacks": ([
            "claw": 15,
            "claw": 15,
            "fangs": 20,
        ]),
        "base hit points": 250,
        "base spell points" : 0,
        "base stamina points" : 150
    ]),
    "boar":([
        "description": "Boars are wild, muscular swine with coarse bristles and sharp tusks. "
            "They are known for their aggressive temperament and will charge at "
            "perceived threats with little provocation. Boars are surprisingly fast "
            "and can inflict serious wounds with their tusks. In the wild, they are "
            "both a challenge for hunters and a danger to the unwary.",
        "category": "animal",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 5,
        "maximum level": 15,
        "attacks": ([
            "tusk": 10,
            "fangs": 5,
        ]),
        "base hit points": 100,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "cat":([
        "description": "Cats are agile, curious, and independent animals, prized for their "
            "grace and hunting prowess. With sharp claws, keen senses, and a "
            "stealthy gait, cats are adept at stalking small prey. They are "
            "often found as companions in homes or prowling the wilds, always "
            "alert and ready to pounce.",
        "category": "animal",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 1,
        "maximum level": 8,
        "attacks": ([
            "claw": 3,
            "claw": 3,
            "fangs": 5,
        ]),
        "base hit points": 10,
        "base spell points" : 0,
        "base stamina points" : 50
    ]),
    "panther":([
        "description": "Panthers are sleek, powerful big cats with jet-black fur and "
            "piercing yellow eyes. Masters of stealth and ambush, they move "
            "silently through dense forests and jungles, striking swiftly at "
            "their prey. Panthers are solitary and territorial, feared by all "
            "who cross their path in the wild.",
        "category": "animal",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "cat" }),
        "minimum level": 6,
        "maximum level": 15,
        "attacks": ([
            "claw": 10,
            "claw": 10,
            "fangs": 10,
        ]),
        "base hit points": 50,
        "base spell points" : 0,
        "base stamina points" : 50
    ]),
    "mountain lion":([
        "description": "Mountain lions, also known as cougars or pumas, are large, tawny "
            "cats native to rugged hills and forests. They are agile climbers and "
            "powerful hunters, capable of leaping great distances to catch their "
            "prey. Mountain lions are solitary and elusive, rarely seen except by "
            "those who know how to track them.",
        "category": "animal",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "cat", "lion" }),
        "minimum level": 6,
        "maximum level": 15,
        "attacks": ([
            "claw": 10,
            "claw": 10,
            "fangs": 10,
        ]),
        "base hit points": 50,
        "base spell points" : 0,
        "base stamina points" : 50
    ]),
    "chimera":([
        "description": "The chimera is a fearsome, mythical beast with the body and head of "
            "a lion, a goat's head rising from its back, and a serpent for a tail. "
            "It is a creature of chaos and terror, capable of breathing fire, "
            "unleashing bolts of lightning, and spewing acid or frost. Chimeras are "
            "rare and deadly, often found in remote, desolate places where few dare "
            "to tread.",
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 25,
        "attacks": ([
            "claw": 10,
            "fangs": 15,
        ]),
        "research": ([
            "fire breath": 25,
            "electricity breath": 25,
            "acid breath": 25,
            "cold breath": 25,
        ]),
        "base hit points": 250,
        "base spell points" : 200,
        "base stamina points" : 100
    ]),
    "cockatrice":([
        "description": "The cockatrice is a small, dragon-like creature with the body of a "
            "rooster and the tail of a serpent. Its beady eyes and sharp beak are "
            "matched only by its deadly magical abilities. The cockatrice is infamous "
            "for its power to paralyze or petrify with a touch or a glance, making it "
            "a dangerous foe despite its size.",
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 10,
        "attacks": ([
            "claw": 10,
            "beak": 15,
        ]),
        "special attacks": ([
            "paralysis": 15,
        ]),
        "base hit points": 150,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "dog":([
        "description": "Dogs are loyal, intelligent, and social animals, often found as "
            "companions to humans and other races. They possess keen senses of smell "
            "and hearing, and are quick to defend their pack or territory. In the wild, "
            "dogs hunt in packs, using teamwork and speed to bring down prey.",
        "category": "animal",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 1,
        "maximum level": 8,
        "attacks": ([
            "claw": 3,
            "fangs": 5,
        ]),
        "base hit points": 10,
        "base spell points" : 0,
        "base stamina points" : 50
    ]),
    "coyote":([
        "description": "Coyotes are cunning, adaptable canines found in a variety of "
            "environments. They are smaller than wolves but just as clever, hunting "
            "alone or in small packs. Coyotes are opportunistic feeders, known for "
            "their yipping calls and ability to thrive near civilization as well as "
            "in the wild.",
        "category": "animal",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 1,
        "maximum level": 9,
        "attacks": ([
            "claw": 3,
            "fangs": 5,
        ]),
        "base hit points": 15,
        "base spell points" : 0,
        "base stamina points" : 50
    ]),
    "white-tail deer":([
        "description": "White-tail deer are graceful, swift herbivores with a distinctive "
            "white underside to their tails. They are alert and skittish, relying on "
            "keen senses and speed to evade predators. Deer are a common sight in "
            "forests and meadows, moving in small herds and feeding on grasses and "
            "leaves.",
        "category": "animal",
        "primary skills":({ "parry", "dodge", "no armor", "listen" }),
        "secondary skills" : ({ "perception", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "deer" }),
        "minimum level": 1,
        "maximum level": 5,
        "attacks": ([
            "hoof": 3,
            "horn": 3,
        ]),
        "base hit points": 10,
        "base spell points" : 0,
        "base stamina points" : 50
    ]),
    "mule deer":([
        "description": "Mule deer are robust, large-eared deer found in hilly and mountainous "
            "regions. They are known for their bounding gait and ability to navigate "
            "rough terrain. Mule deer are social animals, often seen in small groups, "
            "and are prized by hunters for their meat and antlers.",
        "category": "animal",
        "primary skills":({ "parry", "dodge", "no armor", "listen" }),
        "secondary skills" : ({ "perception", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "deer" }),
        "minimum level": 1,
        "maximum level": 5,
        "attacks": ([
            "hoof": 3,
            "horn": 3,
        ]),
        "base hit points": 10,
        "base spell points" : 0,
        "base stamina points" : 50
    ]),
    "moose":([
        "description": "Moose are the largest members of the deer family, towering over most "
            "other animals in the forest. They have long legs, a humped back, and "
            "broad, palmate antlers. Moose are solitary and can be aggressive if "
            "provoked, using their size and strength to defend themselves against "
            "predators.",
        "category": "animal",
        "primary skills":({ "parry", "dodge", "no armor", "listen" }),
        "secondary skills" : ({ "perception", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "deer" }),
        "minimum level": 8,
        "maximum level": 15,
        "attacks": ([
            "hoof": 10,
            "horn": 10,
        ]),
        "base hit points": 150,
        "base spell points" : 0,
        "base stamina points" : 150
    ]),
    "eagle":([
        "description": "Eagles are majestic birds of prey, renowned for their keen eyesight "
            "and powerful talons. They soar high above mountains and forests, "
            "scanning the ground for movement. Eagles are symbols of strength and "
            "freedom, and their sudden, diving attacks are both swift and deadly.",
        "category": "animal",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 3,
        "maximum level": 15,
        "attacks": ([
            "talon": 5,
            "beak": 10,
        ]),
        "base hit points": 20,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "raven":([
        "description": "Ravens are intelligent, adaptable birds with glossy black feathers "
            "and a distinctive, croaking call. They are often associated with omens "
            "and magic, and are known for their problem-solving skills. Ravens can "
            "be found in a variety of environments, scavenging for food and "
            "occasionally forming bonds with adventurers or spellcasters.",
        "category": "animal",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 2,
        "maximum level": 8,
        "attacks": ([
            "talon": 3,
            "beak": 5,
        ]),
        "base hit points": 10,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "gargoyle":([
        "description": "Gargoyles are stone-skinned, winged creatures that perch atop ancient "
            "ruins and castles. By day, they remain motionless, blending in with "
            "statues and architecture. By night, they come alive, hunting for prey "
            "with razor-sharp talons and fangs. Gargoyles are both guardians and "
            "predators, feared for their strength and resilience.",
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 10,
        "attacks": ([
            "talon": 10,
            "talon": 10,
            "fangs": 15,
        ]),
        "base hit points": 100,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "ghoul":([
        "description": "Ghouls are undead creatures, once human, now twisted by dark magic "
            "and insatiable hunger. They haunt graveyards and battlefields, feeding "
            "on the flesh of the dead. Ghouls are swift and cunning, their claws "
            "infused with paralyzing energy. Their presence is often heralded by a "
            "foul stench and the chill of the grave.",
        "category": "undead",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({ "/lib/instances/traits/effects/ethereal" }),
        "potential traits" : ({}),
        "minimum level": 5,
        "attacks": ([
            "claw": 10,
            "undead": 10,
        ]),
        "special attacks": ([
            "paralysis": 5,
        ]),
        "base hit points": 35,
        "base spell points" : 35,
        "base stamina points" : 35
    ]),
    "ghast":([
        "description": "Ghasts are more powerful and foul than ghouls, exuding a nauseating "
            "stench that can sicken the living. They are undead predators, haunting "
            "tombs and crypts, and are known for spreading disease with their touch. "
            "Ghasts are cunning and relentless, making them a terror among the dead.",
        "category": "undead",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 8,
        "attacks": ([
            "claw": 10,
            "undead": 15,
        ]),
        "special attacks": ([
            "disease": 25,
        ]),
        "base hit points": 35,
        "base spell points" : 35,
        "base stamina points" : 35
    ]),
    "gorgon":([
        "description": "Gorgons are monstrous creatures, often depicted as having the body "
            "of a great bull or reptile and the head of a woman with writhing snakes "
            "for hair. Their gaze is said to turn flesh to stone, and their breath "
            "can scorch the earth. Gorgons are rare and deadly, lurking in ancient "
            "ruins and cursed places.",
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 10,
        "attacks": ([
            "claw": 10,
            "fangs": 15,
            "fire": 20
        ]),
        "base hit points": 150,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "fire elemental":([
        "description": "Fire elementals are living embodiments of flame, their bodies "
            "composed of flickering fire and swirling embers. They radiate intense "
            "heat and can ignite anything they touch. Fire elementals are summoned "
            "from the elemental planes and are both beautiful and terrifying to behold.",
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "elemental" }),
        "minimum level": 5,
        "attacks": ([
            "fire": 10,
        ]),
        "base hit points": 40,
        "base spell points" : 40,
        "base stamina points" : 50
    ]),
    "air elemental":([
        "description": "Air elementals are swirling masses of wind and cloud, barely visible "
            "except for the dust and debris caught in their currents. They move with "
            "incredible speed and can buffet foes with blasts of air or bolts of "
            "lightning. Air elementals are unpredictable and difficult to contain.",
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "elemental" }),
        "minimum level": 5,
        "attacks": ([
            "electricity": 10,
        ]),
        "base hit points": 40,
        "base spell points" : 40,
        "base stamina points" : 50
    ]),
    "earth elemental":([
        "description": "Earth elementals are hulking forms of living stone and soil, their "
            "bodies shifting and grinding with every movement. They are nearly "
            "unstoppable, able to smash through walls and crush their enemies with "
            "brute force. Earth elementals are slow but relentless, and their "
            "connection to the land makes them formidable guardians.",
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "elemental" }),
        "minimum level": 5,
        "attacks": ([
            "earth": 10,
        ]),
        "base hit points": 40,
        "base spell points" : 40,
        "base stamina points" : 50
    ]),
    "water elemental":([
        "description": "Water elementals are fluid, ever-changing beings formed from pure "
            "water. They can flow through the smallest cracks, engulfing and drowning "
            "their foes. Water elementals are both graceful and deadly, able to "
            "crash like a wave or freeze their enemies with a touch.",
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "elemental" }),
        "minimum level": 5,
        "attacks": ([
            "water": 10,
            "cold": 5,
        ]),
        "base hit points": 40,
        "base spell points" : 40,
        "base stamina points" : 50
    ]),
    "chaos wisp":([
        "description": "Chaos wisps are small, flickering motes of raw magical energy. "
            "They drift through the air, leaving trails of shifting color and "
            "distortion in their wake. Chaos wisps are unpredictable, sometimes "
            "harmless, sometimes explosively dangerous, and are often drawn to "
            "places of great magical power.",
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "wisp" }),
        "minimum level": 5,
        "attacks": ([
            "chaos": 10,
        ]),
        "base hit points": 40,
        "base spell points" : 40,
        "base stamina points" : 50
    ]),
    "ice wisp":([
        "description": "Ice wisps are ethereal, cold spirits that float silently through "
            "frozen landscapes. Their forms shimmer with frost, and their touch can "
            "chill the air and freeze flesh. Ice wisps are elusive and rarely seen, "
            "appearing only in the coldest, most desolate places.",
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "wisp" }),
        "minimum level": 5,
        "attacks": ([
            "cold": 10,
        ]),
        "base hit points": 40,
        "base spell points" : 40,
        "base stamina points" : 50
    ]),
    "will-o-wisp":([
        "description": "Will-o-wisps are mysterious, floating lights that lure travelers "
            "into danger. They appear as glowing orbs, flickering just out of reach, "
            "and are said to be the spirits of the lost or the mischievous. "
            "Will-o-wisps can drain the energy of the living, leaving only "
            "confusion and despair behind.",
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "wisp" }),
        "minimum level": 5,
        "attacks": ([
            "energy": 10,
        ]),
        "base hit points": 40,
        "base spell points" : 40,
        "base stamina points" : 50
    ]),
    "aura wisp":([
        "description": "Aura wisps are rare, radiant entities composed of pure magical "
            "energy. They glow with a soft, shifting light and are drawn to sources "
            "of arcane power. Aura wisps are generally harmless, but can unleash "
            "bursts of magical force if threatened.",
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "wisp" }),
        "minimum level": 5,
        "attacks": ([
            "magical": 10,
        ]),
        "base hit points": 40,
        "base spell points" : 40,
        "base stamina points" : 50
    ]),
    "griffon":([
        "description": "Griffons are majestic beasts with the body of a lion and the head "
            "and wings of an eagle. They are fierce predators, capable of flight and "
            "deadly in battle. Griffons are often used as mounts by the bravest of "
            "warriors, and their loyalty, once earned, is unbreakable.",
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 15,
        "attacks": ([
            "claw": 10,
            "claw": 10,
            "beak": 15,
            "wing": 10,
        ]),
        "base hit points": 175,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "harpy":([
        "description": "Harpies are monstrous creatures with the bodies of birds and the "
            "faces of women. They are known for their haunting songs, which can "
            "bewitch and lure travelers to their doom. Harpies are vicious and "
            "cruel, attacking with claws and wings from above.",
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 10,
        "attacks": ([
            "claw": 10,
            "claw": 10,
            "wing": 10,
        ]),
        "base hit points": 125,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "hell hound":([
        "description": "Hell hounds are fearsome, supernatural canines wreathed in smoke "
            "and flame. Their eyes glow with infernal fire, and their breath can "
            "scorch flesh and bone. Hell hounds are often found as guardians in the "
            "service of dark powers, and their howls chill the blood of all who hear "
            "them.",
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "hound" }),
        "minimum level": 7,
        "attacks": ([
            "claw": 5,
            "fangs": 5,
            "fire": 5,
        ]),
        "base hit points": 100,
        "base spell points" : 50,
        "base stamina points" : 100
    ]),
    "homunculus":([
        "description": "A homunculus is a small, artificial creature created through "
            "alchemy or magic. It is often humanoid in shape, with leathery skin "
            "and sharp features. Homunculi serve their creators as spies, messengers, "
            "or guardians, and are known for their loyalty and cunning.",
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 5,
        "attacks": ([
            "claw": 5,
            "fangs": 5,
        ]),
        "base hit points": 35,
        "base spell points" : 20,
        "base stamina points" : 20
    ]),
    "hydra":([
        "description": "The hydra is a multi-headed serpent or dragon, infamous for its "
            "regenerative abilities. When one head is severed, two more may grow in "
            "its place. Hydras are formidable opponents, attacking with multiple "
            "fang-filled jaws and powerful claws. They dwell in swamps, lakes, or "
            "caverns, and are feared by all.",
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 20,
        "attacks": ([
            "claw": 10,
            "fangs": 10,
            "fangs" : 10,
            "fangs" : 10,
        ]),
        "base hit points": 250,
        "base spell points" : 100,
        "base stamina points" : 100
    ]),
    "kraken":([
        "description": "The kraken is a legendary sea monster, said to dwell in the "
            "deepest oceans. Its massive tentacles can drag entire ships beneath the "
            "waves, and its fanged maw is large enough to swallow a person whole. "
            "Kraken are rarely seen, but tales of their wrath have haunted sailors "
            "for generations.",
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 15,
        "attacks": ([
            "tentacle": 10,
            "tentacle": 10,
            "fangs": 15,
        ]),
        "base hit points": 150,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "lich":([
        "description": "A lich is a powerful undead sorcerer who has achieved immortality "
            "through dark rituals. Liches retain their intelligence and magical "
            "abilities, commanding legions of undead and wielding forbidden spells. "
            "Their bodies are withered and skeletal, and their presence radiates "
            "an aura of dread.",
        "category": "undead",
        "is humanoid": 1,
        "primary skills":({ "parry", "dodge", "no armor", "staff" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "equipment": ([ 
            "weapons":({ "staffs" }),
            "armor/accessories": ({ "ring", "bracers" })
        ]),
        "minimum level": 25,
        "attacks": ([
            "undead": 25,
            "undead": 25,
            "cold": 35,
            "evil": 15
        ]),
        "research": ([
            "gift of xyris": 1,
            "hand of xyris": 10,
            "soul scourge": 15,
        ]),
        "base hit points": 150,
        "base spell points" : 250,
        "base stamina points" : 100
    ]),
    "manticore":([
        "description": "The manticore is a fearsome beast with the body of a lion, the "
            "wings of a dragon or bat, and a tail bristling with deadly spines. Its "
            "face is often disturbingly human, and its roar can freeze the blood. "
            "Manticores are cunning hunters, using their spiked tails to hurl "
            "projectiles at prey before closing in for the kill.",
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 12,
        "attacks": ([
            "claw": 10,
            "fangs": 10,
            "wing" : 10,
            "tail" : 10,
        ]),
        "base hit points": 150,
        "base spell points" : 100,
        "base stamina points" : 100
    ]),
    "air mephit":([
        "description": "Air mephits are small, impish creatures composed of swirling winds "
            "and translucent, vaporous bodies. Their wings beat rapidly, stirring up "
            "gusts and eddies wherever they go. Mischievous and quick, air mephits "
            "delight in playing pranks and can unleash blasts of wind or razor-sharp "
            "currents to defend themselves.",
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "mephit" }),
        "minimum level": 5,
        "attacks": ([
            "claw": 5,
            "air": 5,
        ]),
        "base hit points": 35,
        "base spell points" : 20,
        "base stamina points" : 20
    ]),
    "earth mephit":([
        "description": "Earth mephits are squat, rocky creatures with pebbly skin and "
            "crumbling wings. Their eyes gleam like polished stones, and their voices "
            "rumble like distant thunder. Earth mephits can hurl clods of dirt or "
            "cause minor tremors, and they are stubborn, tough, and surprisingly "
            "strong for their size.",
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "mephit" }),
        "minimum level": 5,
        "attacks": ([
            "claw": 5,
            "earth": 5,
        ]),
        "base hit points": 35,
        "base spell points" : 20,
        "base stamina points" : 20
    ]),
    "chaos mephit":([
        "description": "Chaos mephits are unpredictable, ever-shifting beings of raw magical "
            "energy. Their forms flicker and change color constantly, and their laughter "
            "is wild and unsettling. They can unleash bursts of chaotic magic, causing "
            "strange and random effects on their surroundings and foes.",
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "mephit" }),
        "minimum level": 5,
        "attacks": ([
            "claw": 5,
            "chaos": 5,
        ]),
        "base hit points": 35,
        "base spell points" : 20,
        "base stamina points" : 20
    ]),
    "ice mephit":([
        "description": "Ice mephits are slender, blue-white creatures with crystalline wings "
            "and frosty breath. Their bodies are cold to the touch, and they leave a "
            "trail of rime wherever they go. Ice mephits can exhale chilling blasts and "
            "are fond of cold, desolate places.",
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "mephit" }),
        "minimum level": 5,
        "attacks": ([
            "claw": 5,
            "cold": 5,
        ]),
        "base hit points": 35,
        "base spell points" : 20,
        "base stamina points" : 20
    ]),
    "storm mephit":([
        "description": "Storm mephits are tempestuous, crackling beings with dark, cloud-like "
            "bodies and eyes that flash with lightning. Their wings resemble storm-tossed "
            "clouds, and they can summon small bolts of electricity or gusts of wind. "
            "Storm mephits are volatile and quick to anger.",
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "mephit" }),
        "minimum level": 5,
        "attacks": ([
            "claw": 5,
            "electricity": 5,
        ]),
        "base hit points": 35,
        "base spell points" : 20,
        "base stamina points" : 20
    ]),
    "blast mephit":([
        "description": "Blast mephits are energetic, explosive creatures with glowing, "
            "pulsating bodies. They are constantly in motion, and their touch can "
            "release bursts of raw energy. Blast mephits are excitable and prone to "
            "sudden, destructive outbursts.",
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "mephit" }),
        "minimum level": 5,
        "attacks": ([
            "claw": 5,
            "energy": 5,
        ]),
        "base hit points": 35,
        "base spell points" : 20,
        "base stamina points" : 20
    ]),
    "flame mephit":([
        "description": "Flame mephits are fiery, impish beings with bodies of flickering "
            "flame and wings of smoke. Their eyes glow like embers, and their laughter "
            "crackles. Flame mephits can ignite objects with a touch and are immune to "
            "heat and fire.",
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "mephit" }),
        "minimum level": 5,
        "attacks": ([
            "claw": 5,
            "fire": 5,
        ]),
        "base hit points": 35,
        "base spell points" : 20,
        "base stamina points" : 20
    ]),
    "aether mephit":([
        "description": "Aether mephits are rare, otherworldly creatures composed of swirling "
            "magical energies. Their forms are translucent and ever-shifting, and they "
            "can manipulate arcane forces to create dazzling displays or defend "
            "themselves. Aether mephits are curious and drawn to sources of magic.",
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "mephit" }),
        "minimum level": 5,
        "attacks": ([
            "claw": 5,
            "magical": 5,
        ]),
        "base hit points": 35,
        "base spell points" : 20,
        "base stamina points" : 20
    ]),
    "psy mephit":([
        "description": "Psy mephits are enigmatic, psychic creatures with shimmering, "
            "iridescent skin and large, expressive eyes. They communicate telepathically "
            "and can unleash bursts of mental energy to confuse or harm their foes. "
            "Psy mephits are elusive and rarely seen.",
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "mephit" }),
        "minimum level": 5,
        "attacks": ([
            "claw": 5,
            "psionic": 5,
        ]),
        "base hit points": 35,
        "base spell points" : 20,
        "base stamina points" : 20
    ]),
    "sonic mephit":([
        "description": "Sonic mephits are slender, blue-gray creatures whose bodies vibrate "
            "with constant, low hums. Their voices can shatter glass and their wings "
            "produce piercing shrieks. Sonic mephits can unleash concussive blasts of "
            "sound to disorient or injure their enemies.",
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "mephit" }),
        "minimum level": 5,
        "attacks": ([
            "claw": 5,
            "sonic": 5,
        ]),
        "research": ([
            "sonic-blast": 5,
        ]),
        "base hit points": 35,
        "base spell points" : 20,
        "base stamina points" : 20
    ]),
    "water mephit":([
        "description": "Water mephits are fluid, blue-skinned creatures with webbed hands and "
            "glistening wings. They are playful and slippery, able to conjure jets of "
            "water or create slick surfaces. Water mephits thrive in damp environments "
            "and are quick to flee danger.",
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "mephit" }),
        "minimum level": 5,
        "attacks": ([
            "claw": 5,
            "water": 5,
        ]),
        "base hit points": 35,
        "base spell points" : 20,
        "base stamina points" : 20
    ]),
    "sear mephit":([
        "description": "Sear mephits are caustic, acid-dripping creatures with pitted, "
            "corroded skin and sharp, jagged wings. They can spit acid or corrode "
            "metal with a touch. Sear mephits are irritable and quick to attack when "
            "provoked.",
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "mephit" }),
        "minimum level": 5,
        "attacks": ([
            "claw": 5,
            "acid": 5,
        ]),
        "base hit points": 35,
        "base spell points" : 20,
        "base stamina points" : 20
    ]),
    "mohrg":([
        "description": "Mohrgs are terrifying undead creatures, the animated remains of "
            "murderers and other evil beings. Their bodies are skeletal, with long, "
            "whiplike tongues and glowing eyes. Mohrgs can paralyze their victims and "
            "are driven by a relentless urge to kill.",
        "category": "undead",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 10,
        "attacks": ([
            "claw": 10,
            "undead": 20,
        ]),
        "special attacks": ([
            "paralysis": 5,
        ]),
        "base hit points": 50,
        "base spell points" : 35,
        "base stamina points" : 35
    ]),
    "mummy":([
        "description": "Mummies are ancient, preserved corpses wrapped in linen and animated "
            "by dark magic. They are slow but powerful, striking fear into the hearts "
            "of the living. Mummies can spread disease and are often found guarding "
            "tombs and lost treasures.",
        "category": "undead",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 12,
        "attacks": ([
            "undead": 15,
            "undead": 15,
        ]),
        "special attacks": ([
            "disease": 35,
        ]),
        "base hit points": 100,
        "base spell points" : 35,
        "base stamina points" : 35
    ]),
    "naga":([
        "description": "Nagas are serpentine creatures with humanoid faces and long, coiling "
            "bodies. They are intelligent and often possess magical abilities. Some "
            "nagas are benevolent guardians, while others are cunning and dangerous, "
            "using poison and spells to defeat their enemies.",
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 10,
        "attacks": ([
            "claw": 15,
            "claw": 15,
        ]),
        "special attacks": ([
            "poison": 15,
        ]),
        "base hit points": 150,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "night hag":([
        "description": "Night hags are fiendish, nightmarish creatures with withered, blue-"
            "black skin and glowing red eyes. They haunt dreams and prey on the souls "
            "of the living, using their magic to curse and torment. Night hags are "
            "cunning and cruel, feared by mortals and immortals alike.",
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "hag" }),
        "minimum level": 10,
        "attacks": ([
            "claw": 10,
            "fangs": 15,
        ]),
        "special attacks": ([
            "disease": 15,
        ]),
        "base hit points": 100,
        "base spell points" : 50,
        "base stamina points" : 100
    ]),
    "marsh hag":([
        "description": "Marsh hags are twisted, green-skinned witches who dwell in fetid "
            "swamps and bogs. They are masters of illusion and enchantment, luring "
            "travelers to their doom. Marsh hags are sly and manipulative, using "
            "their magic to weaken and ensnare their victims.",
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "hag" }),
        "minimum level": 10,
        "attacks": ([
            "claw": 10,
            "fangs": 15,
        ]),
        "special attacks": ([
            "enfeebled": 15,
        ]),
        "base hit points": 100,
        "base spell points" : 50,
        "base stamina points" : 100
    ]),
    "sea hag":([
        "description": "Sea hags are hideous, aquatic witches with slimy, greenish skin and "
            "hair like seaweed. They dwell in coastal caves and underwater lairs, "
            "using their magic to control tides and storms. Sea hags are known for "
            "their ability to curse and slow their enemies, making them dangerous "
            "foes for sailors and adventurers.",
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "hag" }),
        "minimum level": 10,
        "attacks": ([
            "claw": 10,
            "fangs": 15,
        ]),
        "special attacks": ([
            "slow": 15,
        ]),
        "base hit points": 100,
        "base spell points" : 50,
        "base stamina points" : 100
    ]),
    "horse":([
        "description": "Horses are strong, swift, and intelligent animals, valued for their "
            "endurance and loyalty. They are used as mounts, beasts of burden, and "
            "companions by many races. Horses come in many breeds and colors, and "
            "their speed and stamina make them essential for travel and warfare.",
        "category": "animal",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 5,
        "maximum level": 15,
        "attacks": ([
            "hoof": 10,
        ]),
        "base hit points": 50,
        "base spell points" : 0,
        "base stamina points" : 150
    ]),
    "nightmare":([
        "description": "Nightmares are terrifying, supernatural horses with burning manes and "
            "hooves of fire. Their eyes glow with malevolent intelligence, and their "
            "breath reeks of brimstone. Nightmares serve as mounts for fiends and "
            "dark sorcerers, galloping through the night and leaving scorched earth "
            "in their wake.",
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 8,
        "attacks": ([
            "hoof": 10,
            "fire": 10,
        ]),
        "base hit points": 60,
        "base spell points" : 0,
        "base stamina points" : 150
    ]),
    "nukulevee":([
        "description": "The nukulevee is a nightmarish undead creature from legend, appearing "
            "as a monstrous horse with a rider fused to its back. Its flesh is "
            "rotting and its breath is poisonous. The nukulevee spreads terror and "
            "disease wherever it goes, and is nearly impossible to kill.",
        "category": "undead",
        "primary skills":({ "parry", "dodge", "no armor", "pole arm" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 10,
        "attacks": ([
            "hoof": 10,
            "undead": 10,
            "evil": 10,
        ]),
        "equipment": ([ 
            "weapons/pole-arms":({ "spear" })
        ]),
        "base hit points": 100,
        "base spell points" : 0,
        "base stamina points" : 150
    ]),
    "owlbear":([
        "description": "Owlbears are monstrous beasts with the body of a bear and the head "
            "of a giant owl. They are ferocious predators, feared for their strength, "
            "speed, and bone-chilling screeches. Owlbears are territorial and will "
            "attack anything that enters their domain.",
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 15,
        "attacks": ([
            "claw": 10,
            "claw": 10,
            "beak": 20,
        ]),
        "base hit points": 175,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "pegasus":([
        "description": "Pegasi are magnificent, winged horses with pure white coats and "
            "feathered wings. They are symbols of freedom and grace, able to soar "
            "through the skies with ease. Pegasi are gentle but fiercely loyal to "
            "those they trust.",
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 10,
        "attacks": ([
            "hoof": 10,
            "wing": 10,
            "magical": 10
        ]),
        "base hit points": 150,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "phoenix":([
        "description": "The phoenix is a legendary bird of fire and rebirth, with brilliant "
            "plumage that glows like the sun. When slain, a phoenix bursts into flames "
            "and is reborn from its own ashes. Phoenixes are rare and awe-inspiring, "
            "and their tears are said to have healing powers.",
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 10,
        "attacks": ([
            "beak": 10,
            "claw": 10,
            "fire": 10,
        ]),
        "base hit points": 150,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "rat":([
        "description": "Rats are small, agile rodents with sharp teeth and a keen sense of "
            "smell. They thrive in dark, damp places and are known for spreading "
            "disease. Rats are quick to flee danger but can become aggressive when "
            "cornered or in large numbers.",
        "category": "animal",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 1,
        "maximum level": 5,
        "attacks": ([
            "claw": 2,
            "claw": 2,
            "fangs": 2,
        ]),
        "special attacks": ([
            "disease": 1,
        ]),
        "base hit points": 150,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "red squirrel":([
        "description": "Red squirrels are small, energetic rodents with bushy tails and "
            "reddish fur. They are excellent climbers and are often seen darting "
            "through trees in search of nuts and seeds. Red squirrels are territorial "
            "and will fiercely defend their nests.",
        "category": "animal",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 1,
        "maximum level": 5,
        "attacks": ([
            "claw": 2,
            "claw": 2,
            "fangs": 2,
        ]),
        "base hit points": 25,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "gray squirrel":([
        "description": "Gray squirrels are agile, bushy-tailed rodents with gray fur and "
            "white underbellies. They are common in forests and urban areas, known for "
            "their acrobatics and ability to store food for winter. Gray squirrels are "
            "curious and quick to investigate new things.",
        "category": "animal",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 1,
        "maximum level": 5,
        "attacks": ([
            "claw": 2,
            "claw": 2,
            "fangs": 2,
        ]),
        "base hit points": 25,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "chipmunk":([
        "description": "Chipmunks are small, striped rodents with cheek pouches for storing "
            "food. They are quick and nimble, darting through underbrush and burrows. "
            "Chipmunks are known for their chattering calls and industrious nature.",
        "category": "animal",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 1,
        "maximum level": 5,
        "attacks": ([
            "claw": 1,
            "claw": 1,
            "fangs": 1,
        ]),
        "base hit points": 25,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "gopher":([
        "description": "Gophers are burrowing rodents with stout bodies and large front teeth. "
            "They dig extensive tunnel systems and are rarely seen above ground. "
            "Gophers are important for soil aeration but can be pests in gardens and "
            "fields.",
        "category": "animal",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 1,
        "maximum level": 5,
        "attacks": ([
            "claw": 1,
            "claw": 1,
            "fangs": 1,
        ]),
        "base hit points": 25,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "muskrat":([
        "description": "Muskrats are semi-aquatic rodents with dense, waterproof fur and "
            "flattened tails. They build lodges in ponds and streams and are skilled "
            "swimmers. Muskrats feed on aquatic plants and are active year-round.",
        "category": "animal",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 1,
        "maximum level": 5,
        "attacks": ([
            "claw": 2,
            "claw": 2,
            "fangs": 2,
        ]),
        "base hit points": 50,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "porcupine":([
        "description": "Porcupines are slow-moving rodents covered in sharp quills for "
            "protection. When threatened, they raise and rattle their quills, which "
            "can detach and embed in predators. Porcupines feed on bark, leaves, and "
            "roots.",
        "category": "animal",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 1,
        "maximum level": 5,
        "attacks": ([
            "claw": 2,
            "claw": 2,
            "fangs": 2,
        ]),
        "base hit points": 50,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "raccoon":([
        "description": "Raccoons are clever, nocturnal mammals with masked faces and ringed "
            "tails. They are dexterous and curious, able to open containers and solve "
            "simple puzzles. Raccoons are omnivorous and often forage in both wild and "
            "urban environments.",
        "category": "animal",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 1,
        "maximum level": 5,
        "attacks": ([
            "claw": 2,
            "claw": 2,
            "fangs": 2,
        ]),
        "base hit points": 50,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "skunk":([
        "description": "Skunks are small, black-and-white mammals famous for their potent "
            "defensive spray. When threatened, they raise their tails and release a "
            "foul-smelling liquid that deters most predators. Skunks are omnivorous "
            "and mostly nocturnal, foraging for insects, plants, and small animals.",
        "category": "animal",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 1,
        "maximum level": 5,
        "attacks": ([
            "claw": 2,
            "claw": 2,
            "fangs": 2,
        ]),
        "base hit points": 50,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "opossum":([
        "description": "Opossums are nocturnal marsupials known for their adaptability and "
            "unique defense mechanisms. With grayish fur, prehensile tails, and sharp "
            "teeth, they forage for fruits, insects, and small animals. When threatened, "
            "opossums may bare their teeth, hiss, or famously 'play dead' to avoid "
            "predators. They are excellent climbers and often nest in hollow trees or "
            "abandoned burrows.",
        "category": "animal",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 1,
        "maximum level": 5,
        "attacks": ([
            "claw": 2,
            "claw": 2,
            "fangs": 2,
        ]),
        "base hit points": 50,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "groundhog":([
        "description": "Groundhogs, also called woodchucks, are burrowing rodents with stout "
            "bodies and short legs. They are skilled diggers, creating complex tunnel "
            "systems for shelter and hibernation. Groundhogs feed on grasses, fruits, "
            "and vegetables, and are often seen standing upright to survey their "
            "surroundings. Their burrows provide homes for many other animals.",
        "category": "animal",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 1,
        "maximum level": 5,
        "attacks": ([
            "claw": 2,
            "claw": 2,
            "fangs": 2,
        ]),
        "base hit points": 50,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "beaver":([
        "description": "Beavers are large, aquatic rodents famous for their dam-building "
            "abilities. With powerful jaws and large, flat tails, they construct lodges "
            "and dams that shape waterways and create wetlands. Beavers have waterproof "
            "fur and webbed feet, making them excellent swimmers. They feed on bark, "
            "leaves, and aquatic plants.",
        "category": "animal",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 1,
        "maximum level": 5,
        "attacks": ([
            "claw": 2,
            "claw": 2,
            "fangs": 2,
        ]),
        "base hit points": 50,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "otter":([
        "description": "Otters are playful, semi-aquatic mammals with sleek bodies and thick, "
            "waterproof fur. They are agile swimmers, using webbed feet and strong tails "
            "to navigate rivers and lakes. Otters feed on fish, crustaceans, and small "
            "aquatic animals, and are known for their intelligence and social behavior.",
        "category": "animal",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 1,
        "maximum level": 5,
        "attacks": ([
            "claw": 3,
            "claw": 3,
            "fangs": 2,
        ]),
        "base hit points": 100,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "mink":([
        "description": "Minks are small, sleek carnivorous mammals with dark brown fur and a "
            "white underbelly. They are agile hunters, preying on fish, rodents, and "
            "birds along riverbanks and wetlands. Minks are solitary and territorial, "
            "valued for their luxurious pelts.",
        "category": "animal",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 1,
        "maximum level": 5,
        "attacks": ([
            "claw": 3,
            "claw": 3,
            "fangs": 2,
        ]),
        "base hit points": 50,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "fisher":([
        "description": "Fishers are medium-sized, agile mustelids with dark fur and bushy "
            "tails. They are skilled climbers and fierce predators, known for hunting "
            "porcupines and small mammals in dense forests. Fishers are solitary and "
            "elusive, rarely seen by humans.",
        "category": "animal",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 1,
        "maximum level": 5,
        "attacks": ([
            "claw": 3,
            "claw": 3,
            "fangs": 2,
        ]),
        "base hit points": 50,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "badger":([
        "description": "Badgers are sturdy, burrowing mammals with distinctive black-and-white "
            "striped faces. They are known for their digging ability, powerful claws, "
            "and fierce defense of their setts. Badgers feed on insects, small animals, "
            "and roots, and are mostly nocturnal.",
        "category": "animal",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 1,
        "maximum level": 5,
        "attacks": ([
            "claw": 3,
            "claw": 3,
            "fangs": 2,
        ]),
        "base hit points": 100,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),    
    "sea serpent":([
        "description": "Sea serpents are massive, serpentine creatures that dwell in the "
            "deepest oceans and large lakes. Their long, scaled bodies can reach "
            "incredible lengths, and they are known for their powerful jaws and "
            "whiplike tails. Legends tell of sea serpents dragging ships beneath the "
            "waves and terrorizing sailors with their sudden appearances.",
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "serpent" }),
        "minimum level": 10,
        "attacks": ([
            "fangs": 25,
            "tail" : 10,
        ]),
        "base hit points": 250,
        "base spell points" : 100,
        "base stamina points" : 100
    ]),
    "shadow":([
        "description": "Shadows are incorporeal undead that appear as dark, shifting forms. "
            "They drain the strength and vitality of the living, leaving only cold and "
            "fear in their wake. Shadows are nearly impossible to strike with physical "
            "weapons and are often found haunting ruins and graveyards.",
        "category": "undead",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({ "/lib/instances/traits/effects/ethereal" }),
        "potential traits" : ({}),
        "minimum level": 10,
        "attacks": ([
            "claw": 10,
            "undead": 10,
            "undead": 10,
        ]),
        "special attacks": ([
            "enfeebled": 1,
        ]),
        "base hit points": 150,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "skeleton":([
        "description": "Skeletons are animated bones of the dead, held together by dark magic. "
            "They are tireless, fearless, and immune to pain, often serving as soldiers "
            "or guardians for necromancers. Skeletons can wield weapons and armor, and "
            "attack relentlessly until destroyed.",
        "category": "undead",
        "is humanoid": 1,
        "primary skills":({ "parry", "dodge", "shield", "long sword",
            "hand and a half sword", "short sword", "dagger",
            "two-handed sword", "plate armor", "splint armor",
            "chainmail", "scalemail", "hard leather", "soft leather",
            "no armor", "axe", "mace", "hammer", "flail", "staff",
            "pole arm", "archer" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "equipment": ([ 
            "weapons":({ "swords", "axes", "maces", "hammers",
                "flails", "bows", "daggers", "staffs",
                "pole-arms" }),
            "armor": ({ "light-armor", "medium-armor", "heavy-armor" }),
            "armor/accessories": ({ "belt", "boots", "coif", "gloves", 
                "helmet", "ring" })
        ]),
        "minimum level": 3,
        "attacks": ([
            "undead": 5,
        ]),
        "base hit points": 25,
        "base spell points" : 0,
        "base stamina points" : 25
    ]),
    "spectre":([
        "description": "Spectres are malevolent, incorporeal undead that haunt the living. "
            "They appear as ghostly figures, radiating cold and despair. Spectres drain "
            "the life force of their victims and are nearly immune to physical attacks. "
            "They are often bound to cursed places or objects.",
        "category": "undead",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({ "/lib/instances/traits/effects/ethereal" }),
        "potential traits" : ({}),
        "minimum level": 5,
        "attacks": ([
            "undead": 10,
            "undead": 10,
        ]),
        "base hit points": 35,
        "base spell points" : 0,
        "base stamina points" : 35
    ]),
    "giant spider":([
        "description": "Giant spiders are monstrous arachnids, often found lurking in dark "
            "forests, caves, or ruins. Their venomous fangs can paralyze or kill prey, "
            "and their webs are strong enough to entangle even large creatures. Giant "
            "spiders are cunning ambush predators, feared by adventurers.",
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "spider" }),
        "minimum level": 10,
        "attacks": ([
            "claw": 10,
            "fangs": 25,
        ]),
        "special attacks": ([
            "poison": 20,
        ]),
        "base hit points": 100,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "tarrasque":([
        "description": "The tarrasque is a legendary, nearly unstoppable monster of immense "
            "size and power. Its armored hide is impervious to most weapons, and its "
            "rampages can devastate entire regions. The tarrasque is rarely seen, but "
            "its appearance is a harbinger of destruction and chaos.",
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 20,
        "attacks": ([
            "claw": 10,
            "claw": 10,
            "fangs": 25,
            "tail": 15,
        ]),
        "base hit points": 250,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "terlang":([
        "description": "Terlings are humanoid creatures with avian features, including taloned "
            "feet and sharp beaks. They are agile and quick, often forming tribal "
            "societies in remote mountains or forests. Terlangs are skilled with swords "
            "and light armor, and are known for their keen senses and swift attacks.",
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "shield", "long sword",
            "hand and a half sword", "short sword", "dagger",
            "two-handed sword", "chainmail", "scalemail", 
            "hard leather", "soft leather", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "equipment": ([ 
            "weapons":({ "swords" }),
            "armor": ({ "light-armor", "medium-armor" }),
        ]),
        "minimum level": 5,
        "attacks": ([
            "talon": 10,
        ]),
        "base hit points": 30,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "treant":([
        "description": "Treants are ancient, sentient trees that act as guardians of the "
            "forest. Towering and powerful, they can uproot themselves to move and "
            "defend their woodland homes. Treants are wise and patient, but fierce when "
            "provoked, using their massive limbs to crush foes.",
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 20,
        "attacks": ([
            "unarmed": 35,
            "unarmed": 35,
        ]),
        "base hit points": 150,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "troglodyte":([
        "description": "Troglodytes are reptilian humanoids that dwell in deep caves and "
            "underground tunnels. They are primitive and savage, attacking intruders "
            "with crude weapons and natural ferocity. Troglodytes emit a foul stench "
            "that can sicken their enemies.",
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 10,
        "attacks": ([
            "unarmed": 15,
            "unarmed": 15,
        ]),
        "base hit points": 70,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "unicorn":([
        "description": "Unicorns are legendary, horse-like creatures with a single spiraled "
            "horn on their foreheads. They are symbols of purity and grace, possessing "
            "magical healing powers and the ability to repel evil. Unicorns are elusive, "
            "dwelling in enchanted forests and appearing only to the worthy.",
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 15,
        "attacks": ([
            "hoof": 10,
            "horn": 20,
            "magical": 15,
        ]),
        "base hit points": 150,
        "base spell points" : 200,
        "base stamina points" : 100
    ]),
    "wolf":([
        "description": "Wolves are social, intelligent canines that hunt in packs. They are "
            "known for their keen senses, endurance, and teamwork. Wolves communicate "
            "with howls and body language, and are both respected and feared in the "
            "wild. They prey on deer, elk, and other large animals.",
        "category": "animal",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 3,
        "maximum level": 20,
        "attacks": ([
            "claw": 6,
            "fangs": 10,
        ]),
        "base hit points": 30,
        "base spell points" : 0,
        "base stamina points" : 50
    ]),
    "red fox":([
        "description": "Red foxes are small, cunning canines with reddish fur, bushy tails, "
            "and sharp features. They are adaptable hunters, feeding on rodents, birds, "
            "and fruit. Red foxes are known for their intelligence, agility, and "
            "elusiveness, thriving in both wild and urban environments.",
        "category": "animal",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "fox" }),
        "minimum level": 3,
        "maximum level": 10,
        "attacks": ([
            "claw": 5,
            "fangs": 8,
        ]),
        "base hit points": 30,
        "base spell points" : 0,
        "base stamina points" : 50
    ]),
    "fennec fox":([
        "description": "Fennec foxes are small desert canines with oversized ears and pale "
            "fur. Their large ears help dissipate heat and detect prey underground. "
            "Fennec foxes are nocturnal, feeding on insects, rodents, and fruit, and "
            "are well-adapted to arid environments.",
        "category": "animal",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "fox" }),
        "minimum level": 3,
        "maximum level": 10,
        "attacks": ([
            "claw": 5,
            "fangs": 8,
        ]),
        "base hit points": 30,
        "base spell points" : 0,
        "base stamina points" : 50
    ]),
    "gray fox":([
        "description": "Gray foxes are agile, tree-climbing canines with gray fur and black-"
            "tipped tails. They are omnivorous, eating small animals, insects, and "
            "fruit. Gray foxes are shy and elusive, often found in forests and brushy "
            "areas.",
        "category": "animal",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "fox" }),
        "minimum level": 3,
        "maximum level": 10,
        "attacks": ([
            "claw": 5,
            "fangs": 8,
        ]),
        "base hit points": 30,
        "base spell points" : 0,
        "base stamina points" : 50
    ]),
    "kit fox":([
        "description": "Kit foxes are small, swift canines with large ears and bushy tails. "
            "They inhabit arid and semi-arid regions, hunting rodents, insects, and "
            "birds. Kit foxes are nocturnal and use their keen senses to avoid "
            "predators and find food.",
        "category": "animal",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "fox" }),
        "minimum level": 3,
        "maximum level": 10,
        "attacks": ([
            "claw": 5,
            "fangs": 8,
        ]),
        "base hit points": 30,
        "base spell points" : 0,
        "base stamina points" : 50
    ]),
    "timber wolf":([
        "description": "Timber wolves are large, powerful subspecies of gray wolf, known for "
            "their stamina and pack hunting skills. They inhabit forests and wilderness "
            "areas, preying on deer, elk, and other large animals. Timber wolves are "
            "highly social and communicate with howls.",
        "category": "animal",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "wolf" }),
        "minimum level": 3,
        "maximum level": 20,
        "attacks": ([
            "claw": 6,
            "fangs": 10,
        ]),
        "base hit points": 30,
        "base spell points" : 0,
        "base stamina points" : 50
    ]),
    "gray wolf":([
        "description": "Gray wolves are the largest wild members of the dog family, with thick "
            "fur and bushy tails. They are highly adaptable, living in forests, tundra, "
            "and grasslands. Gray wolves hunt in packs and are known for their "
            "intelligence and complex social structure.",
        "category": "animal",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "wolf" }),
        "minimum level": 3,
        "maximum level": 20,
        "attacks": ([
            "claw": 6,
            "fangs": 10,
        ]),
        "base hit points": 30,
        "base spell points" : 0,
        "base stamina points" : 50
    ]),
    "red wolf":([
        "description": "Red wolves are rare, medium-sized canines with reddish fur and long "
            "legs. They are shy and elusive, living in small packs in forests and "
            "swamps. Red wolves are critically endangered and are known for their "
            "keen senses and adaptability.",
        "category": "animal",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "wolf" }),
        "minimum level": 3,
        "maximum level": 20,
        "attacks": ([
            "claw": 6,
            "fangs": 10,
        ]),
        "base hit points": 30,
        "base spell points" : 0,
        "base stamina points" : 50
    ]),
    "wolverine":([
        "description": "Wolverines are stocky, muscular mustelids with thick fur and strong "
            "jaws. They are solitary and fiercely territorial, known for their "
            "fearlessness and ability to take down prey much larger than themselves. "
            "Wolverines are found in cold, northern forests and tundra.",
        "category": "animal",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 2,
        "maximum level": 12,
        "attacks": ([
            "claw": 5,
            "claw": 5,
            "fangs": 7,
        ]),
        "base hit points": 20,
        "base spell points" : 0,
        "base stamina points" : 50
    ]),
    "weasel":([
        "description": "Weasels are small, slender carnivores with brown fur and white "
            "underbellies. They are agile hunters, preying on rodents, birds, and eggs. "
            "Weasels are known for their speed, curiosity, and ability to squeeze into "
            "tight spaces.",
        "category": "animal",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 1,
        "maximum level": 8,
        "attacks": ([
            "claw": 3,
            "claw": 3,
            "fangs": 5,
        ]),
        "base hit points": 10,
        "base spell points" : 0,
        "base stamina points" : 50
    ]),
    "warg":([
        "description": "Wargs are large, evil wolves with shaggy fur and glowing eyes. They "
            "are often ridden by goblins or orcs and are known for their savagery and "
            "cunning. Wargs hunt in packs and are feared throughout the wild lands.",
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 5,
        "attacks": ([
            "claw": 10,
            "fangs": 15,
        ]),
        "base hit points": 30,
        "base spell points" : 0,
        "base stamina points" : 50
    ]),
    "vampire":([
        "description": "Vampires are undead beings that feed on the blood of the living. "
            "They retain a humanoid form, often appearing pale and alluring. Vampires "
            "possess supernatural strength, speed, and the ability to charm or dominate "
            "their victims. They are vulnerable to sunlight, holy symbols, and certain "
            "magics.",
        "category": "undead",
        "is humanoid": 1,
        "primary skills":({ "parry", "dodge", "shield", "long sword",
            "hand and a half sword", "short sword", "dagger",
            "two-handed sword", "plate armor", "splint armor",
            "chainmail", "scalemail", "hard leather", "soft leather",
            "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "equipment": ([ 
            "weapons":({ "swords" }),
        ]),
        "minimum level": 15,
        "attacks": ([
            "undead": 10,
            "undead": 10,
            "cold": 10,
        ]),
        "base hit points": 150,
        "base spell points" : 250,
        "base stamina points" : 100
    ]),
    "wight":([
        "description": "Wights are undead creatures that drain the life force of the living. "
            "They appear as gaunt, corpse-like figures with glowing eyes. Wights are "
            "often found haunting tombs and battlefields, and their touch can paralyze "
            "or kill.",
        "category": "undead",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({ "/lib/instances/traits/effects/ethereal" }),
        "potential traits" : ({}),
        "minimum level": 6,
        "attacks": ([
            "claw": 10,
            "undead": 12,
        ]),
        "special attacks": ([
            "paralysis": 5,
        ]),
        "base hit points": 35,
        "base spell points" : 35,
        "base stamina points" : 35
    ]),
    "zombie":([
        "description": "Zombies are reanimated corpses, driven by dark magic or curses. They "
            "are slow, relentless, and immune to pain, attacking with brute force. "
            "Zombies are often used as mindless servants by necromancers and can be "
            "found in graveyards, crypts, and battlefields.",
        "category": "undead",
        "is humanoid": 1,
        "primary skills":({ "parry", "dodge", "shield", "long sword",
            "hand and a half sword", "short sword", "dagger",
            "two-handed sword", "plate armor", "splint armor",
            "chainmail", "scalemail", "hard leather", "soft leather",
            "no armor", "axe", "mace", "hammer", "flail", "staff",
            "pole arm", "archer" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "equipment": ([ 
            "weapons":({ "swords", "axes", "maces", "hammers",
                "flails", "bows", "daggers", "staffs",
                "pole-arms" }),
            "armor": ({ "light-armor", "medium-armor", "heavy-armor" }),
            "armor/accessories": ({ "belt", "boots", "coif", "gloves", 
                "helmet", "ring" })
        ]),
        "minimum level": 2,
        "attacks": ([
            "undead": 5,
        ]),
        "base hit points": 25,
        "base spell points" : 0,
        "base stamina points" : 25
    ]),
    "wraith":([
        "description": "Wraiths are incorporeal undead that appear as shadowy, robed figures. "
            "They drain the life energy of the living and are nearly immune to physical "
            "attacks. Wraiths are feared for their chilling touch and haunting presence.",
        "category": "undead",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({ "/lib/instances/traits/effects/ethereal" }),
        "potential traits" : ({}),
        "minimum level": 12,
        "attacks": ([
            "claw": 10,
            "undead": 15,
            "undead": 15,
        ]),
        "special attacks": ([
            "paralysis": 5,
        ]),
        "base hit points": 150,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "scion of blood":([
        "description": "Scions of blood are magical entities formed from the essence of blood "
            "and life force. They appear as shifting, crimson figures and wield powers "
            "over vitality, pain, and healing. Scions of blood are often summoned for "
            "dark rituals or as guardians of forbidden knowledge.",
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor", "unarmed",
            "spellcraft", "blood" }),
        "secondary skills" : ({ "perception", "listen", "spot", 
            "anatomy and physiology", "astronomy", "chemistry", "mathematics",
            "physics", "evocation", "magical essence" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "scion" }),
        "minimum level": 1,
        "attacks": ([
            "evil": 10,
        ]),
        "base hit points": 50,
        "base spell points" : 50,
        "base stamina points" : 50
    ]),
    "scion of electricity":([
        "description": "Scions of electricity are beings of pure elemental energy, crackling "
            "with lightning and surrounded by a faint electric aura. They can unleash "
            "bolts of electricity and manipulate storms. Scions of electricity are "
            "summoned by powerful mages or found in places of great elemental power.",
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor", "unarmed",
            "spellcraft", "elemental air" }),
        "secondary skills" : ({ "perception", "listen", "spot", 
            "anatomy and physiology", "astronomy", "chemistry", "mathematics",
            "physics", "evocation", "magical essence" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "scion" }),
        "minimum level": 1,
        "attacks": ([
            "electricity": 10,
        ]),
        "base hit points": 50,
        "base spell points" : 50,
        "base stamina points" : 50
    ]),
    "scion of ice":([
        "description": "Scions of ice are elemental beings formed from frost and cold. Their "
            "bodies shimmer with crystalline patterns, and their presence chills the "
            "air. Scions of ice wield powers over freezing winds and can encase foes in "
            "ice. They are often found in arctic realms or summoned by winter magics.",
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor", "unarmed",
            "spellcraft", "elemental water" }),
        "secondary skills" : ({ "perception", "listen", "spot", 
            "anatomy and physiology", "astronomy", "chemistry", "mathematics",
            "physics", "evocation", "magical essence" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "scion" }),
        "minimum level": 1,
        "attacks": ([
            "cold": 10,
        ]),
        "base hit points": 50,
        "base spell points" : 50,
        "base stamina points" : 50
    ]),
    "scion of energy":([
        "description": "Scions of energy are manifestations of raw magical or elemental power. "
            "They appear as shifting, luminous forms and can unleash blasts of pure "
            "energy. Scions of energy are unpredictable and often summoned for "
            "destructive purposes or as guardians of arcane secrets.",
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor", "unarmed",
            "spellcraft", "evocation" }),
        "secondary skills" : ({ "perception", "listen", "spot", 
            "anatomy and physiology", "astronomy", "chemistry", "mathematics",
            "physics", "destruction", "magical essence" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "scion" }),
        "minimum level": 1,
        "attacks": ([
            "energy": 10,
        ]),
        "base hit points": 50,
        "base spell points" : 50,
        "base stamina points" : 50
    ]),
    "scion of fire":([
        "description": "Scions of fire are blazing elemental beings, their forms wreathed in "
            "flame and heat. They can ignite anything they touch and hurl fire at their "
            "enemies. Scions of fire are summoned by pyromancers or found in volcanic "
            "regions and places of elemental upheaval.",
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor", "unarmed",
            "spellcraft", "elemental fire" }),
        "secondary skills" : ({ "perception", "listen", "spot", 
            "anatomy and physiology", "astronomy", "chemistry", "mathematics",
            "physics", "evocation", "magical essence" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "scion" }),
        "minimum level": 1,
        "attacks": ([
            "fire": 10,
        ]),
        "base hit points": 50,
        "base spell points" : 50,
        "base stamina points" : 50
    ]),
    "scion of the spirit":([
        "description": "Scions of the spirit are ethereal beings composed of pure spiritual "
            "energy. They appear as luminous, shifting forms and possess powers over "
            "the mind, soul, and unseen realms. Scions of the spirit are summoned for "
            "guidance, protection, or to serve as intermediaries between worlds.",
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor", "unarmed",
            "spellcraft", "spirit" }),
        "secondary skills" : ({ "perception", "listen", "spot", 
            "anatomy and physiology", "astronomy", "chemistry", "mathematics",
            "physics", "evocation", "magical essence" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "scion" }),
        "minimum level": 1,
        "attacks": ([
            "magical": 10,
        ]),
        "base hit points": 50,
        "base spell points" : 50,
        "base stamina points" : 50
    ]),
    "flame guardian": ([
        "description": "A flame guardian is a divine servant of Ferianth, "
            "manifested as a humanoid figure of living fire. Its body flickers "
            "and shifts between deep orange and blinding white, leaving trails "
            "of embers wherever it moves. Eyes of pure flame regard the world "
            "with fierce devotion to its summoner.",
        "category": "creatures",
        "primary skills": ({ "elemental fire", "evocation", "spellcraft",
            "no armor", "dodge" }),
        "secondary skills": ({ "parry", "perception" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "guardian", "flame", "fire" }),
        "attacks": ([
            "fire": 25
        ]),
        "base hit points": 100,
        "base spell points": 150,
        "base stamina points": 50
    ]),
]);
