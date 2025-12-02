//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef armor_h
#define armor_h

#include "/lib/include/inventory.h"

protected string *armorCategories = ({ "chainmail", "plate armor", 
    "clothing", "splint armor", "scale armor", "hard leather", "soft leather",
    "gloves", "helmet", "jewelry" });

protected mapping armorBlueprints = ([
    "chainmail": ([
        "type": "armor",
        "subtype": "medium armor",
        "skill to craft": 10,
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/armor/chainmail/craftChainmail.c":(["type":"research"]),
            "metal crafting": (["type":"skill", "value": 3]),
            "armorer": (["type":"skill", "value": 7]),
        ]),
        "crafting materials": ([
            "metal": 10,
            "textile": 2
        ]),
        "skill to use": "chainmail",
        "default ac": 6,
        "default location": Armor,
        "default encumberance": 20,
        "default weight": 8,
        "default material": "iron",
        "default value": 500,
        "default description": "This armor consists of small metal rings linked together in a tightly-woven "
            "mesh. A thin textile jacket that pads the user has been sewn into the interior.",
        "base experience": 10,
    ]),
    "byrnie": ([
        "type": "armor",
        "subtype": "medium armor",
        "skill to craft": 15,
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/armor/chainmail/craftChainmail.c":(["type":"research"]),
            "metal crafting": (["type":"skill", "value": 3]),
            "armorer": (["type":"skill", "value": 12]),
        ]),
        "crafting materials": ([
            "metal": 10,
            "textile": 2
        ]),
        "skill to use": "chainmail",
        "default ac": 7,
        "default location": Armor,
        "default encumberance": 20,
        "default weight": 8,
        "default material": "iron",
        "default value": 1500,
        "default description": "This armor consists of small metal rings linked together in a tightly-woven "
            "mesh. A thin textile jacket that pads the user has been sewn into the interior.",
        "base experience": 15,
    ]),
    "hauberk": ([
        "type": "armor",
        "subtype": "medium armor",
        "skill to craft": 10,
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/armor/chainmail/craftChainmail.c":(["type":"research"]),
            "metal crafting": (["type":"skill", "value": 3]),
            "armorer": (["type":"skill", "value": 7]),
        ]),
        "crafting materials": ([
            "metal": 8,
            "textile": 2
        ]),
        "skill to use": "chainmail",
        "default ac": 5,
        "default location": Armor,
        "default encumberance": 20,
        "default weight": 8,
        "default material": "iron",
        "default value": 450,
        "default description": "This hauberk consists of small metal rings linked together in a tightly-woven "
            "mesh. A thin textile jacket that pads the user has been sewn into the interior.",
        "base experience": 10,
    ]),
    "gambeson": ([
        "type": "armor",
        "subtype": "light armor",
        "skill to craft": 5,
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/armor/craftClothing.c":(["type":"research"]),
            "sewing": (["type":"skill", "value": 3]),
            "armorer": (["type":"skill", "value": 2]),
        ]),
        "crafting materials": ([
            "textile": 10
        ]),
        "skill to use": "no armor",
        "default ac": 1,
        "default location": Armor,
        "default encumberance": 6,
        "default weight": 4,
        "default material": "linen",
        "default value": 25,
        "default description": "This is a padded, tightly-quilted textile jacket.",
        "base experience": 5,
    ]),
    "robes": ([
        "type": "armor",
        "subtype": "clothing",
        "skill to craft": 5,
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/armor/craftClothing.c":(["type":"research"]),
            "sewing": (["type":"skill", "value": 3]),
            "armorer": (["type":"skill", "value": 2]),
        ]),
        "crafting materials": ([
            "textile": 10
        ]),
        "skill to use": "no armor",
        "default ac": 1,
        "default location": Armor,
        "default encumberance": 6,
        "default weight": 4,
        "default material": "linen",
        "default value": 75,
        "default description": "This is a thick textile robe.",
        "base experience": 5,
    ]),
    "ornate robes": ([
        "type": "armor",
        "subtype": "clothing",
        "skill to craft": 8,
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/armor/craftClothing.c":(["type":"research"]),
            "sewing": (["type":"skill", "value": 1]),
            "metal crafting": (["type":"skill", "value": 1]),
            "gem crafting": (["type":"skill", "value": 1]),
            "weaving and beadwork": (["type":"skill", "value": 3]),
            "armorer": (["type":"skill", "value": 2]),
        ]),
        "crafting materials": ([
            "textile": 10,
            "crystal": 1,
            "metal": 1
        ]),
        "skill to use": "no armor",
        "default ac": 1,
        "default location": Armor,
        "default encumberance": 6,
        "default weight": 5,
        "default material": "linen",
        "default value": 475,
        "default description": "This is a thick textile robe with intricately woven threads of metal "
            "embroidered into it and a stunning array of crystal sewn upon its surface.",
        "base experience": 10,
    ]),
    "dress": ([
        "type": "armor",
        "subtype": "clothing",
        "skill to craft": 5,
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/armor/craftClothing.c":(["type":"research"]),
            "sewing": (["type":"skill", "value": 1]),
            "weaving and beadwork": (["type":"skill", "value": 4]),
        ]),
        "crafting materials": ([
            "textile": 10
        ]),
        "skill to use": "no armor",
        "default ac": 0,
        "default location": Armor,
        "default encumberance": 2,
        "default weight": 2,
        "default material": "linen",
        "default value": 25,
        "default description": "This is an exquisite textile dress.",
        "base experience": 5,
    ]),
    "gown": ([
        "type": "armor",
        "subtype": "clothing",
        "skill to craft": 5,
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/armor/craftClothing.c":(["type":"research"]),
            "sewing": (["type":"skill", "value": 1]),
            "weaving and beadwork": (["type":"skill", "value": 4]),
        ]),
        "crafting materials": ([
            "textile": 9
        ]),
        "skill to use": "no armor",
        "default ac": 0,
        "default location": Armor,
        "default encumberance": 2,
        "default weight": 2,
        "default material": "linen",
        "default value": 25,
        "default description": "This is a gown of textile.",
        "base experience": 5,
    ]),
    "shirt": ([
        "type": "armor",
        "subtype": "clothing",
        "skill to craft": 5,
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/armor/craftClothing.c":(["type":"research"]),
            "sewing": (["type":"skill", "value": 1]),
            "weaving and beadwork": (["type":"skill", "value": 4]),
        ]),
        "crafting materials": ([
            "textile": 5
        ]),
        "skill to use": "no armor",
        "default ac": 0,
        "default location": Armor,
        "default encumberance": 1,
        "default weight": 1,
        "default material": "linen",
        "default value": 15,
        "default description": "This is a comfortable textile shirt.",
        "base experience": 5,
    ]),
    "pants": ([
        "type": "armor",
        "subtype": "clothing",
        "skill to craft": 5,
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/armor/craftClothing.c":(["type":"research"]),
            "sewing": (["type":"skill", "value": 1]),
            "weaving and beadwork": (["type":"skill", "value": 4]),
        ]),
        "crafting materials": ([
            "textile": 5
        ]),
        "skill to use": "no armor",
        "default ac": 0,
        "default location": LegGreaves,
        "default encumberance": 2,
        "default weight": 1,
        "default material": "linen",
        "default value": 15,
        "default description": "These are pants made out of textile.",
        "base experience": 5,
    ]),
    "kilt": ([
        "type": "armor",
        "subtype": "clothing",
        "skill to craft": 5,
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/armor/craftClothing.c":(["type":"research"]),
            "sewing": (["type":"skill", "value": 1]),
            "weaving and beadwork": (["type":"skill", "value": 4]),
        ]),
        "crafting materials": ([
            "textile": 4
        ]),
        "skill to use": "no armor",
        "default ac": 0,
        "default location": LegGreaves,
        "default encumberance": 2,
        "default weight": 1,
        "default material": "linen",
        "default value": 15,
        "default description": "This is a kilt made out of textile.",
        "base experience": 5,
    ]),
    "skirt": ([
        "type": "armor",
        "subtype": "clothing",
        "skill to craft": 5,
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/armor/craftClothing.c":(["type":"research"]),
            "sewing": (["type":"skill", "value": 1]),
            "weaving and beadwork": (["type":"skill", "value": 4]),
        ]),
        "crafting materials": ([
            "textile": 4
        ]),
        "skill to use": "no armor",
        "default ac": 0,
        "default location": LegGreaves,
        "default encumberance": 2,
        "default weight": 1,
        "default material": "linen",
        "default value": 15,
        "default description": "This is a skirt made out of textile.",
        "base experience": 5,
    ]),
    "shorts": ([
        "type": "armor",
        "subtype": "clothing",
        "skill to craft": 5,
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/armor/craftClothing.c":(["type":"research"]),
            "sewing": (["type":"skill", "value": 1]),
            "weaving and beadwork": (["type":"skill", "value": 4]),
        ]),
        "crafting materials": ([
            "textile": 3
        ]),
        "skill to use": "no armor",
        "default ac": 0,
        "default location": LegGreaves,
        "default encumberance": 1,
        "default weight": 1,
        "default material": "linen",
        "default value": 10,
        "default description": "These are shorts made out of textile.",
        "base experience": 5,
    ]),
    "brigandine": ([
        "type": "armor",
        "subtype": "heavy armor",
        "skill to craft": 10,
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/armor/heavy-armor/craftSplintArmor.c":(["type":"research"]),
            "metal crafting": (["type":"skill", "value": 3]),
            "armorer": (["type":"skill", "value": 7]),
        ]),
        "crafting materials": ([
            "metal": 10,
            "textile": 2
        ]),
        "skill to use": "splint armor",
        "default ac": 7,
        "default location": Armor,
        "default encumberance": 25,
        "default weight": 10,
        "default material": "iron",
        "default value": 700,
        "default description": "This is a garment of heavy textile lined with small, tightly-fitted metal "
            "plates riveted to the fabric.",
        "base experience": 10,
    ]),
    "banded mail": ([
        "type": "armor",
        "subtype": "heavy armor",
        "skill to craft": 10,
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/armor/heavy-armor/craftSplintArmor.c":(["type":"research"]),
            "metal crafting": (["type":"skill", "value": 3]),
            "armorer": (["type":"skill", "value": 7]),
        ]),
        "crafting materials": ([
            "metal": 10,
            "textile": 2
        ]),
        "skill to use": "splint armor",
        "default ac": 6,
        "default location": Armor,
        "default encumberance": 25,
        "default weight": 9,
        "default material": "iron",
        "default value": 600,
        "default description": "Thick, rigid metal bands woven into a textile surcoat protect almost the whole body of "
            "this armor's wearer. It is hinged at the joints, but is "
            "still heavy and restrictive, but provides good protection.",
        "base experience": 10,
    ]),
    "splint mail": ([
        "type": "armor",
        "subtype": "heavy armor",
        "skill to craft": 10,
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/armor/heavy-armor/craftSplintArmor.c":(["type":"research"]),
            "metal crafting": (["type":"skill", "value": 5]),
            "armorer": (["type":"skill", "value": 5]),
        ]),
        "crafting materials": ([
            "metal": 12,
            "textile": 2
        ]),
        "skill to use": "splint armor",
        "default ac": 6,
        "default location": Armor,
        "default encumberance": 25,
        "default weight": 10,
        "default material": "iron",
        "default value": 550,
        "default description": "This is a garment of textile lined with tightly-fitted metal "
            "bars riveted to the fabric. Where flexibility is needed, metal chainmail is used to fill the gaps.",
        "base experience": 10,
    ]),
    "scale armor": ([
        "type": "armor",
        "subtype": "heavy armor",
        "skill to craft": 15,
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/armor/heavy-armor/craftScaleArmor.c":(["type":"research"]),
            "leatherworking": (["type":"skill", "value": 3]),
            "metal crafting": (["type":"skill", "value": 3]),
            "armorer": (["type":"skill", "value": 9]),
        ]),
        "crafting materials": ([
            "metal": 6,
            "leather": 6
        ]),
        "skill to use": "scalemail",
        "default ac": 6,
        "default location": Armor,
        "default encumberance": 20,
        "default weight": 9,
        "default material": "iron",
        "default value": 585,
        "default description": "This is a garment of leather lined with small, overlapping metal "
            "scales like those from a fish riveted to the fabric.",
        "base experience": 10,
    ]),
    "laminar armor": ([
        "type": "armor",
        "subtype": "heavy armor",
        "skill to craft": 12,
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/armor/heavy-armor/craftPlateArmor.c":(["type":"research"]),
            "metal crafting": (["type":"skill", "value": 3]),
            "armorer": (["type":"skill", "value": 9]),
        ]),
        "crafting materials": ([
            "metal": 12,
            "textile": 4
        ]),
        "skill to use": "plate armor",
        "default ac": 9,
        "default location": Armor,
        "default encumberance": 35,
        "default weight": 15,
        "default material": "iron",
        "default value": 2000,
        "default description": "This is a garment of textile lined with horizontal overlapping metal "
            "bands riveted to the fabric.",
        "base experience": 10,
    ]),
    "plate mail": ([
        "type": "armor",
        "subtype": "heavy armor",
        "skill to craft": 12,
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/armor/heavy-armor/craftPlateArmor.c":(["type":"research"]),
            "metal crafting": (["type":"skill", "value": 3]),
            "armorer": (["type":"skill", "value": 9]),
        ]),
        "crafting materials": ([
            "metal": 12,
            "textile": 4
        ]),
        "skill to use": "plate armor",
        "default ac": 8,
        "default location": Armor,
        "default encumberance": 30,
        "default weight": 12,
        "default material": "iron",
        "default value": 1500,
        "default description": "A gambeson of textile upon which sits a breastplate of "
            "solid metal. The extremeties are covered in metal chainmail.",
        "base experience": 10,
    ]),
    "breastplate": ([
        "type": "armor",
        "subtype": "heavy armor",
        "skill to craft": 12,
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/armor/heavy-armor/craftPlateArmor.c":(["type":"research"]),
            "metal crafting": (["type":"skill", "value": 3]),
            "armorer": (["type":"skill", "value": 9]),
        ]),
        "crafting materials": ([
            "metal": 8,
            "textile": 2
        ]),
        "skill to use": "plate armor",
        "default ac": 7,
        "default location": Armor,
        "default encumberance": 25,
        "default weight": 10,
        "default material": "iron",
        "default value": 1000,
        "default description": "A gambeson of textile upon which sits a breastplate of "
            "solid metal.",
        "base experience": 10,
    ]),
    "plate armor": ([
        "type": "armor",
        "subtype": "heavy armor",
        "skill to craft": 15,
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/armor/heavy-armor/craftPlateArmor.c":(["type":"research"]),
            "metal crafting": (["type":"skill", "value": 5]),
            "armorer": (["type":"skill", "value": 10]),
        ]),
        "crafting materials": ([
            "metal": 15,
            "textile": 4
        ]),
        "skill to use": "plate armor",
        "default ac": 10,
        "default location": Armor,
        "default encumberance": 40,
        "default weight": 15,
        "default material": "iron",
        "default value": 2500,
        "default description": "A gambeson of textile upon which sits a breastplate of "
            "solid metal. The extremeties are covered in segmented, overlapping bands of metal "
            "providing some level of flexibility.",
        "base experience": 15,
    ]),
    "boiled leather": ([
        "type": "armor",
        "subtype": "medium armor",
        "skill to craft": 15,
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/armor/craftLeatherArmor.c":(["type":"research"]),
            "leatherworking": (["type":"skill", "value": 8]),
            "armorer": (["type":"skill", "value": 5]),
            "chemistry": (["type":"skill", "value": 2]),
        ]),
        "crafting materials": ([
            "leather": 10,
            "textile": 2
        ]),
        "skill to use": "hard leather",
        "default ac": 4,
        "default location": Armor,
        "default encumberance": 20,
        "default weight": 5,
        "default material": "leather",
        "default value": 250,
        "default description": "This is a jacket of leather that has been treated after tanning "
            "so that it is tough and rigid. It has had textile quilting sewn into the interior.",
        "base experience": 10,
    ]),
    "hard leather": ([
        "type": "armor",
        "subtype": "medium armor",
        "skill to craft": 5,
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/armor/craftLeatherArmor.c":(["type":"research"]),
            "leatherworking": (["type":"skill", "value": 3]),
            "armorer": (["type":"skill", "value": 2]),
        ]),
        "crafting materials": ([
            "leather": 10,
            "textile": 2
        ]),
        "skill to use": "hard leather",
        "default ac": 3,
        "default location": Armor,
        "default encumberance": 15,
        "default weight": 4,
        "default material": "leather",
        "default value": 225,
        "default description": "This is a jacket of leather that has been treated as part of the tanning "
            "process such that the resultant armor is tough and rigid. It has had textile quilting sewn into the interior.",
        "base experience": 10,
    ]),
    "lamellar leather": ([
        "type": "armor",
        "subtype": "medium armor",
        "skill to craft": 15,
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/armor/heavy-armor/craftSplintArmor.c":(["type":"research"]),
            "metal crafting": (["type":"skill", "value": 5]),
            "leatherworking": (["type":"skill", "value": 5]),
            "armorer": (["type":"skill", "value": 5]),
        ]),
        "crafting materials": ([
            "metal": 6,
            "leather": 6,
            "textile": 2
        ]),
        "skill to use": "splint armor",
        "default ac": 6,
        "default location": Armor,
        "default encumberance": 15,
        "default weight": 5,
        "default material": "leather",
        "default value": 310,
        "default description": "This rigid leather jacket that has had small rectangular plates of "
            "metal sewn on its surface in horizontal rows. It has had textile quilting sewn into the interior.",
        "base experience": 15,
    ]),
    "soft leather": ([
        "type": "armor",
        "subtype": "light armor",
        "skill to craft": 5,
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/armor/craftLeatherArmor.c":(["type":"research"]),
            "leatherworking": (["type":"skill", "value": 3]),
            "armorer": (["type":"skill", "value": 2]),
        ]),
        "crafting materials": ([
            "leather": 10,
            "textile": 2
        ]),
        "skill to use": "soft leather",
        "default ac": 1,
        "default location": Armor,
        "default encumberance": 5,
        "default weight": 3,
        "default material": "leather",
        "default value": 100,
        "default description": "This is a vest of leather that has been treated as part of the tanning "
            "process such that it is pliable and offers a great deal of movement. It has had textile quilting sewn into the interior.",
        "base experience": 5,
    ]),
    "leather jacket": ([
        "type": "armor",
        "subtype": "light armor",
        "skill to craft": 8,
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/armor/craftLeatherArmor.c":(["type":"research"]),
            "leatherworking": (["type":"skill", "value": 5]),
            "armorer": (["type":"skill", "value": 3]),
        ]),
        "crafting materials": ([
            "leather": 8,
            "textile": 2
        ]),
        "skill to use": "soft leather",
        "default ac": 2,
        "default location": Armor | ArmGreaves,
        "default encumberance": 5,
        "default weight": 3,
        "default material": "leather",
        "default value": 100,
        "default description": "This is a jacket of leather that has been treated as part of the tanning "
            "process such that it is pliable and offers a great deal of movement. It has had textile quilting sewn into the interior.",
        "base experience": 5,
    ]),
    "padded armor": ([
        "type": "armor",
        "subtype": "light armor",
        "skill to craft": 5,
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/armor/craftClothing.c":(["type":"research"]),
            "sewing": (["type":"skill", "value": 3]),
            "armorer": (["type":"skill", "value": 2]),
        ]),
        "crafting materials": ([
            "textile": 10
        ]),
        "skill to use": "soft leather",
        "default ac": 1,
        "default location": Armor,
        "default encumberance": 5,
        "default weight": 4,
        "default material": "leather",
        "default value": 50,
        "default description": "This is a padded, tightly-quilted textile jacket.",
        "base experience": 5,
    ]),
    "ring mail": ([
        "type": "armor",
        "subtype": "medium armor",
        "skill to craft": 10,
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/armor/chainmail/craftChainmail.c":(["type":"research"]),
            "leatherworking": (["type":"skill", "value": 3]),
            "metal crafting": (["type":"skill", "value": 2]),
            "armorer": (["type":"skill", "value": 5]),
        ]),
        "crafting materials": ([
            "metal": 6,
            "leather": 6
        ]),
        "skill to use": "chainmail",
        "default ac": 4,
        "default location": Armor,
        "default encumberance": 16,
        "default weight": 7,
        "default material": "iron",
        "default value": 300,
        "default description": "This is a vest of leather that has been treated as part of the tanning "
            "process such that it is pliable and offers a great deal of movement. It has had losely linked "
            "rings of metal sewn on its surface.",
        "base experience": 10,
    ]),
   "gloves": ([
        "type": "armor",
        "subtype": "accessory",
        "skill to craft": 5,
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/armor/craftGloves.c":(["type":"research"]),
            "sewing": (["type":"skill", "value": 1]),
            "leatherworking": (["type":"skill", "value": 4]),
        ]),
        "crafting materials": ([
            "textile": 1,
            "leather": 1
        ]),
        "default location": Gloves,
        "default encumberance": 1,
        "default weight": 1,
        "default material": "leather",
        "default value": 25,
        "default description": "These are leather gloves that has been treated as part of the tanning "
            "process such that it is pliable and very flexible. It has had textile quilting sewn into the interior.",
        "base experience": 5,
    ]),
   "gauntlets": ([
        "type": "armor",
        "subtype": "accessory",
        "skill to craft": 7,
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/armor/craftGloves.c":(["type":"research"]),
            "metal crafting": (["type":"skill", "value": 5]),
        ]),
        "crafting materials": ([
            "metal": 2,
            "leather": 1
        ]),
        "default location": Gloves,
        "default encumberance": 3,
        "default weight": 1,
        "default material": "iron",
        "default value": 50,
        "default description": "These are leather gloves with tightly-fitted overlapping bands of "
            "metal riveted to the surface.",
        "base experience": 5,
    ]),
    "helmet": ([
        "type": "armor",
        "subtype": "accessory",
        "skill to craft": 5,
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/armor/craftHelmet.c":(["type":"research"]),
            "metal crafting": (["type":"skill", "value": 5]),
        ]),
        "crafting materials": ([
            "helmet design": (["metal": 2, "leather": 1 ]),
            "crest": (["metal": 0, "crystal": 0, "plumage": 0, "skeletal": 0 ])
        ]),
        "default location": Helmet,
        "default ac": 1,
        "default encumberance": 1,
        "default weight": 1,
        "default material": "iron",
        "default value": 50,
        "default description": "This is a helmet.",
        "base experience": 5,
    ]),
    "helm": ([
        "type": "armor",
        "subtype": "accessory",
        "skill to craft": 5,
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/armor/craftHelmet.c":(["type":"research"]),
            "metal crafting": (["type":"skill", "value": 5]),
        ]),
        "crafting materials": ([
            "helm design": (["metal": 3, "leather": 1 ]),
            "crest": (["metal": 0, "crystal": 0, "plumage": 0, "skeletal" : 0])
        ]),
        "default location": Helmet,
        "default ac": 1,
        "default encumberance": 1,
        "default weight": 1,
        "default material": "iron",
        "default value": 50,
        "default description": "This is a helm.",
        "base experience": 5,
    ]),
    "coif": ([
        "type": "armor",
        "subtype": "accessory",
        "skill to craft": 10,
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/armor/craftHelmet.c":(["type":"research"]),
            "metal crafting": (["type":"skill", "value": 10]),
        ]),
        "crafting materials": ([
            "metal": 3,
            "leather": 1
        ]),
        "skill to use": "chainmail",
        "default ac": 2,
        "default location": Helmet,
        "default weight": 2,
        "default encumberance": 10,
        "default material": "iron",
        "default value": 100,
        "default description": "This is a coif of small metal rings linked together in a tightly-woven "
            "mesh. A thin leather cap has been sewn into the interior to give it form.",
        "base experience": 5,
    ]),
    "circlet": ([
        "type": "armor",
        "subtype": "accessory",
        "skill to craft": 10,
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/armor/craftJewelry.c":(["type":"research"]),
            "metal crafting": (["type":"skill", "value": 8]),
            "gem crafting": (["type":"skill", "value": 2]),
        ]),
        "crafting materials": ([
            "metal": 2,
            "fillet design": (["metal": 0, "crystal": 0 ])
        ]),
        "default location": Helmet,
        "default ac": 0,
        "default encumberance": 1,
        "default weight": 1,
        "default material": "silver",
        "default value": 350,
        "default description": "This is a thin circlet of metal.",
        "base experience": 5,
    ]),
    "diadem": ([
        "type": "armor",
        "subtype": "accessory",
        "skill to craft": 10,
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/armor/craftJewelry.c":(["type":"research"]),
            "metal crafting": (["type":"skill", "value": 8]),
            "gem crafting": (["type":"skill", "value": 2]),
        ]),
        "crafting materials": ([
            "metal": 2,
            "fillet design": (["metal": 0, "crystal": 0 ])
        ]),
        "default location": Helmet,
        "default ac": 0,
        "default encumberance": 1,
        "default weight": 1,
        "default material": "silver",
        "default value": 350,
        "default description": "This is an ornamental metal diadem.",
        "base experience": 10,
    ]),
    "tiara": ([
        "type": "armor",
        "subtype": "accessory",
        "skill to craft": 10,
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/armor/craftJewelry.c":(["type":"research"]),
            "metal crafting": (["type":"skill", "value": 8]),
            "gem crafting": (["type":"skill", "value": 2]),
        ]),
        "crafting materials": ([
            "metal": 2,
            "fillet design": (["metal": 0, "crystal": 0 ]),
            "tiara design": (["metal": 0, "crystal": 0 ]),
        ]),
        "default location": Helmet,
        "default ac": 0,
        "default encumberance": 1,
        "default weight": 1,
        "default material": "silver",
        "default value": 350,
        "default description": "This is an ornamental metal tiara.",
        "base experience": 10,
    ]),
    "crown": ([
        "type": "armor",
        "subtype": "accessory",
        "skill to craft": 10,
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/armor/craftJewelry.c":(["type":"research"]),
            "metal crafting": (["type":"skill", "value": 8]),
            "gem crafting": (["type":"skill", "value": 2]),
        ]),
        "crafting materials": ([
            "metal": 3,
            "fillet design": (["metal": 0, "crystal": 0 ]),
            "crown design": (["metal": 0, "crystal": 0 ]),
        ]),
        "default location": Helmet,
        "default ac": 0,
        "default encumberance": 1,
        "default weight": 1,
        "default material": "silver",
        "default value": 350,
        "default description": "This is an ornamental metal crown.",
        "base experience": 10,
    ]),
    "hat": ([
        "type": "armor",
        "subtype": "accessory",
        "skill to craft": 5,
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/armor/craftClothing.c":(["type":"research"]),
            "sewing": (["type":"skill", "value": 3]),
            "weaving and beadwork": (["type":"skill", "value": 2]),
        ]),
        "crafting materials": ([
            "textile": 3
        ]),
        "default location": Helmet,
        "default ac": 1,
        "default encumberance": 1,
        "default weight": 1,
        "default material": "linen",
        "default value": 15,
        "default description": "This is a hat made out of textile.",
        "base experience": 5,
    ]),
    "boots": ([
        "type": "armor",
        "subtype": "accessory",
        "skill to craft": 5,
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/armor/craftClothing.c":(["type":"research"]),
            "sewing": (["type":"skill", "value": 1]),
            "leatherworking": (["type":"skill", "value": 4]),
        ]),
        "crafting materials": ([
            "textile": 1,
            "leather": 3
        ]),
        "default location": Boots,
        "default encumberance": 1,
        "default weight": 1,
        "default material": "leather",
        "default value": 25,
        "default description": "These are leather boots with textile sewn into its interior.",
        "base experience": 5,
    ]),
    "shoes": ([
        "type": "armor",
        "subtype": "accessory",
        "skill to craft": 5,
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/armor/craftClothing.c":(["type":"research"]),
            "sewing": (["type":"skill", "value": 1]),
            "leatherworking": (["type":"skill", "value": 4]),
        ]),
        "crafting materials": ([
            "textile": 1,
            "leather": 2
        ]),
        "default location": Boots,
        "default encumberance": 1,
        "default weight": 1,
        "default material": "leather",
        "default value": 25,
        "default description": "These are leather shoes that have had their interior lined with textile.",
        "base experience": 5,
    ]),
    "sandals": ([
        "type": "armor",
        "subtype": "accessory",
        "skill to craft": 5,
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/armor/craftClothing.c":(["type":"research"]),
            "sewing": (["type":"skill", "value": 1]),
            "leatherworking": (["type":"skill", "value": 4]),
        ]),
        "crafting materials": ([
            "textile": 1,
            "leather": 2
        ]),
        "default location": Boots,
        "default encumberance": 1,
        "default weight": 1,
        "default material": "linen",
        "default value": 25,
        "default description": "These are leather sandals that have had their surface lined with textile.",
        "base experience": 5,
    ]),
    "sabaton": ([
        "type": "armor",
        "subtype": "accessory",
        "skill to craft": 10,
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/armor/craftClothing.c":(["type":"research"]),
            "metal crafting": (["type":"skill", "value": 10])
        ]),
        "crafting materials": ([
            "textile": 1,
            "metal": 3
        ]),
        "default ac": 2,
        "default location": Boots,
        "default encumberance": 3,
        "default weight": 2,
        "default material": "iron",
        "default value": 125,
        "default description": "These are boots of overlapping bands of metal. They have had "
            "textile woven into the interior for comfort.",
        "base experience": 10,
    ]),
    "ring": ([
        "type": "armor",
        "subtype": "accessory",
        "skill to craft": 5,
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/armor/craftJewelry.c":(["type":"research"]),
            "metal crafting": (["type":"skill", "value": 5])
        ]),
        "crafting materials": ([
            "metal": 1,
            "ring design": (["metal": 0, "crystal": 0 ])
        ]),
        "default location": Ring,
        "default encumberance": 1,
        "default material": "silver",
        "default value": 150,
        "default description": "This is a small band of metal worn on the finger.",
        "base experience": 10,
    ]),
    "cloak": ([
        "type": "armor",
        "subtype": "clothing",
        "skill to craft": 5,
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/armor/craftClothing.c":(["type":"research"]),
            "sewing": (["type":"skill", "value": 1]),
            "weaving and beadwork": (["type":"skill", "value": 4]),
        ]),
        "crafting materials": ([
            "textile": 4,
            "metal": 1
        ]),
        "default location": Cloak,
        "default encumberance": 1,
        "default weight": 1,
        "default material": "linen",
        "default value": 25,
        "default description": "This is a cloak of textile. A small brooch of metal fastens it to the user.",
        "base experience": 5,
    ]),
    "amulet": ([
        "type": "armor",
        "subtype": "accessory",
        "skill to craft": 10,
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/armor/craftJewelry.c":(["type":"research"]),
            "metal crafting": (["type":"skill", "value": 5]),
            "gem crafting": (["type":"skill", "value": 5]),
        ]),
        "crafting materials": ([
            "metal":1,
            "jewelry chain": (["metal": 1 ]),
            "pendant design": (["metal": 0, "crystal": 0 ])
        ]),
        "default location": Amulet,
        "default encumberance": 1,
        "default material": "iron",
        "default value": 75,
        "default description": "This is an amulet made of metal.",
        "base experience": 10,
    ]),
    "necklace": ([
        "type": "armor",
        "subtype": "accessory",
        "skill to craft": 10,
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/armor/craftJewelry.c":(["type":"research"]),
            "metal crafting": (["type":"skill", "value": 5]),
            "gem crafting": (["type":"skill", "value": 5]),
        ]),
        "crafting materials": ([
            "metal":1,
            "jewelry chain": (["metal": 1 ]),
            "pendant design": (["metal": 0, "crystal": 0 ])
        ]),
        "default location": Amulet,
        "default encumberance": 1,
        "default material": "silver",
        "default value": 125,
        "default description": "This is necklace made of metal.",
        "base experience": 10,
    ]),
    "belt": ([
        "type": "armor",
        "subtype": "accessory",
        "skill to craft": 5,
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/armor/craftClothing.c":(["type":"research"]),
            "metal crafting": (["type":"skill", "value": 1]),
            "leatherworking": (["type":"skill", "value": 4]),
        ]),
        "crafting materials": ([
            "metal": 1,
            "leather": 3
        ]),
        "default location": Belt,
        "default encumberance": 1,
        "default weight": 1,
        "default material": "leather",
        "default value": 25,
        "default description": "This is a belt made out of leather. It has a metal buckle.",
        "base experience": 5,
    ]),
    "sash": ([
        "type": "armor",
        "subtype": "accessory",
        "skill to craft": 5,
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/armor/craftClothing.c":(["type":"research"]),
            "sewing": (["type":"skill", "value": 1]),
            "weaving and beadwork": (["type":"skill", "value": 4]),
        ]),
        "crafting materials": ([
            "textile": 4
        ]),
        "default location": Belt,
        "default encumberance": 1,
        "default weight": 1,
        "default material": "linen",
        "default value": 25,
        "default description": "This is a sash made out of textile.",
        "base experience": 5,
    ]),
    "padded arm greaves": ([
        "type":"armor",
        "subtype" : "light armor",
        "skill to craft" : 5,
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/armor/craftClothing.c":(["type":"research"]),
            "sewing": (["type":"skill", "value": 1]),
            "weaving and beadwork": (["type":"skill", "value": 4]),
        ]),
        "crafting materials": ([
            "textile": 4
        ]),
        "default location" : ArmGreaves,
        "default encumberance" : 1,
        "default weight" : 1,
        "default material" : "linen",
        "default value" : 40,
        "default description" : "This is a pair of padded textile arm greaves.",
        "base experience": 5,
    ]),
    "padded leg greaves": ([
        "type": "armor",
        "subtype": "light armor",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/armor/craftClothing.c":(["type":"research"]),
            "sewing": (["type":"skill", "value": 1]),
            "weaving and beadwork": (["type":"skill", "value": 4]),
        ]),
        "crafting materials": ([
            "textile": 4
        ]),
        "skill to craft": 5,
        "default location": LegGreaves,
        "default encumberance": 1,
        "default weight": 1,
        "default material": "linen",
        "default value": 40,
        "default description": "This is a pair of padded textile leg greaves.",
        "base experience": 5,
    ]),
    "leather arm greaves": ([
        "type":"armor",
        "subtype" : "light armor",
        "skill to craft" : 5,
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/armor/craftLeatherArmor.c":(["type":"research"]),
            "sewing": (["type":"skill", "value": 1]),
            "leatherworking": (["type":"skill", "value": 4]),
        ]),
        "crafting materials": ([
            "leather": 4
        ]),
        "default ac": 1,
        "default location" : ArmGreaves,
        "default encumberance" : 1,
        "default weight" : 1,
        "default material" : "leather",
        "default value" : 40,
        "default description" : "This is a pair of leather arm greaves.",
        "base experience": 5,
    ]),
    "leather leg greaves": ([
        "type": "armor",
        "subtype": "light armor",
        "skill to craft": 5,
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/armor/craftLeatherArmor.c":(["type":"research"]),
            "sewing": (["type":"skill", "value": 1]),
            "leatherworking": (["type":"skill", "value": 4]),
        ]),
        "crafting materials": ([
            "leather": 4
        ]),
        "default ac": 1,
        "default location": LegGreaves,
        "default encumberance": 1,
        "default weight": 1,
        "default material": "leather",
        "default value": 40,
        "default description": "This is a pair of leather leg greaves.",
        "base experience": 5,
    ]),
    "plate arm greaves": ([
        "type":"armor",
        "subtype" : "heavy armor",
        "skill to craft" : 5,
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/armor/heavy-armor/craftPlateArmor.c":(["type":"research"]),
            "metal crafting": (["type":"skill", "value": 5]),
        ]),
        "crafting materials": ([
            "metal": 4,
            "textile": 1
        ]),
        "default ac": 2,
        "default location" : ArmGreaves,
        "default encumberance" : 2,
        "default weight" : 2,
        "default material" : "iron",
        "default value" : 75,
        "default description" : "This is a pair of metal arm greaves padded by textile.",
        "base experience": 5,
    ]),
    "plate leg greaves": ([
        "type": "armor",
        "subtype": "heavy armor",
        "skill to craft": 5,
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/armor/heavy-armor/craftPlateArmor.c":(["type":"research"]),
            "metal crafting": (["type":"skill", "value": 5]),
        ]),
        "crafting materials": ([
            "metal": 4,
            "textile": 1
        ]),
        "default ac": 2,
        "default location": LegGreaves,
        "default encumberance": 2,
        "default weight": 2,
        "default material": "iron",
        "default value": 75,
        "default description": "This is a pair of metal leg greaves padded by textile.",
        "base experience": 5,
    ]),
    "bracers": ([
        "type": "armor",
        "subtype": "accessory",
        "skill to craft": 15,
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/armor/craftJewelry.c":(["type":"research"]),
            "metal crafting": (["type":"skill", "value": 3]),
            "gem crafting": (["type":"skill", "value": 2]),
            "leatherworking": (["type":"skill", "value": 10]),
        ]),
        "crafting materials": ([
            "metal": 1,
            "crystal": 1,
            "leather": 3
        ]),
        "default location": Bracers,
        "default encumberance": 1,
        "default weight": 1,
        "default material": "leather",
        "default value": 200,
        "default description": "This is a small leather bracer that covers the bearer's forearm. "
            "It has had intricately woven strands of metal sewn into it and is further adorned "
            "an attractively-cut crystal.",
        "base experience": 10,
    ]),
    "bracelet": ([
        "type": "armor",
        "subtype": "accessory",
        "skill to craft": 15,
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/armor/craftJewelry.c":(["type":"research"]),
            "metal crafting": (["type":"skill", "value": 3]),
            "gem crafting": (["type":"skill", "value": 2]),
            "leatherworking": (["type":"skill", "value": 10]),
        ]),
        "crafting materials": ([
            "metal":1,
            "jewelry chain": (["metal": 1 ]),
            "pendant design": (["metal": 0, "crystal": 0 ])
        ]),
        "default location": Bracers,
        "default encumberance": 1,
        "default weight": 1,
        "default material": "leather",
        "default value": 200,
        "default description": "This is a small metal bracelet that covers the bearer's wrist.",
        "base experience": 10,
    ]),
]);

#endif
