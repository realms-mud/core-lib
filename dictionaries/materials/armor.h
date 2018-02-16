//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private nosave string *armorCategories = ({ "chainmail", "plate armor", 
    "clothing", "splint armor", "scale armor", "leather armor", "gloves",
    "helmet", "jewelry" });
private nosave mapping armorBlueprints = ([
    "chainmail": ([
        "type": "armor",
        "subtype": "medium armor",
        "skill to craft": 10,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/armor/craftChainmail.c":(["type":"research"]),
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
        "default description": ""
    ]),
    "hauberk": ([
        "type": "armor",
        "subtype": "medium armor",
        "skill to craft": 10,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/armor/craftChainmail.c":(["type":"research"]),
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
        "default description": ""
    ]),
    "gambeson": ([
        "type": "armor",
        "subtype": "light armor",
        "skill to craft": 5,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/armor/craftClothing.c":(["type":"research"]),
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
        "default description": ""
    ]),
    "robes": ([
        "type": "armor",
        "subtype": "clothing",
        "skill to craft": 5,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/armor/craftClothing.c":(["type":"research"]),
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
        "default description": ""
    ]),
    "ornate robes": ([
        "type": "armor",
        "subtype": "clothing",
        "skill to craft": 8,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/armor/craftClothing.c":(["type":"research"]),
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
        "default description": ""
    ]),
    "dress": ([
        "type": "armor",
        "subtype": "clothing",
        "skill to craft": 5,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/armor/craftClothing.c":(["type":"research"]),
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
        "default description": ""
    ]),
    "gown": ([
        "type": "armor",
        "subtype": "clothing",
        "skill to craft": 5,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/armor/craftClothing.c":(["type":"research"]),
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
        "default description": ""
    ]),
    "shirt": ([
        "type": "armor",
        "subtype": "clothing",
        "skill to craft": 5,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/armor/craftClothing.c":(["type":"research"]),
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
        "default description": ""
    ]),
    "pants": ([
        "type": "armor",
        "subtype": "clothing",
        "skill to craft": 5,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/armor/craftClothing.c":(["type":"research"]),
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
        "default description": ""
    ]),
    "kilt": ([
        "type": "armor",
        "subtype": "clothing",
        "skill to craft": 5,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/armor/craftClothing.c":(["type":"research"]),
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
        "default description": ""
    ]),
    "skirt": ([
        "type": "armor",
        "subtype": "clothing",
        "skill to craft": 5,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/armor/craftClothing.c":(["type":"research"]),
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
        "default description": ""
    ]),
    "shorts": ([
        "type": "armor",
        "subtype": "clothing",
        "skill to craft": 5,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/armor/craftClothing.c":(["type":"research"]),
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
        "default description": ""
    ]),
    "brigandine": ([
        "type": "armor",
        "subtype": "heavy armor",
        "skill to craft": 10,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/armor/craftSplintArmor.c":(["type":"research"]),
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
        "default description": ""
    ]),
    "banded mail": ([
        "type": "armor",
        "subtype": "heavy armor",
        "skill to craft": 10,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/armor/craftSplintArmor.c":(["type":"research"]),
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
        "default description": "Thick, rigid metal bands protect almost the whole body of "
            "this armor's wearer. It is hinged at the joints, but is "
            "still heavy and restrictive, but provides good protection."
    ]),
    "splint mail": ([
        "type": "armor",
        "subtype": "heavy armor",
        "skill to craft": 10,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/armor/craftSplintArmor.c":(["type":"research"]),
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
        "default description": ""
    ]),
    "scale armor": ([
        "type": "armor",
        "subtype": "heavy armor",
        "skill to craft": 15,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/armor/craftScaleArmor.c":(["type":"research"]),
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
        "default description": ""
    ]),
    "laminar armor": ([
        "type": "armor",
        "subtype": "heavy armor",
        "skill to craft": 12,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/armor/craftPlateArmor.c":(["type":"research"]),
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
        "default description": ""
    ]),
    "plate mail": ([
        "type": "armor",
        "subtype": "heavy armor",
        "skill to craft": 12,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/armor/craftPlateArmor.c":(["type":"research"]),
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
        "default description": ""
    ]),
    "breastplate": ([
        "type": "armor",
        "subtype": "heavy armor",
        "skill to craft": 12,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/armor/craftPlateArmor.c":(["type":"research"]),
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
        "default description": ""
    ]),
    "plate armor": ([
        "type": "armor",
        "subtype": "heavy armor",
        "skill to craft": 15,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/armor/craftPlateArmor.c":(["type":"research"]),
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
        "default description": ""
    ]),
    "boiled leather": ([
        "type": "armor",
        "subtype": "medium armor",
        "skill to craft": 15,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/armor/craftLeatherArmor.c":(["type":"research"]),
            "leatherworking": (["type":"skill", "value": 10]),
            "armorer": (["type":"skill", "value": 5]),
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
        "default description": ""
    ]),
    "hard leather": ([
        "type": "armor",
        "subtype": "medium armor",
        "skill to craft": 5,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/armor/craftLeatherArmor.c":(["type":"research"]),
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
        "default description": ""
    ]),
    "lamellar leather": ([
        "type": "armor",
        "subtype": "medium armor",
        "skill to craft": 10,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/armor/craftLeatherArmor.c":(["type":"research"]),
            "leatherworking": (["type":"skill", "value": 5]),
            "armorer": (["type":"skill", "value": 5]),
        ]),
        "crafting materials": ([
            "leather": 10,
            "textile": 2
        ]),
        "skill to use": "hard leather",
        "default ac": 4,
        "default location": Armor,
        "default encumberance": 15,
        "default weight": 5,
        "default material": "leather",
        "default value": 310,
        "default description": ""
    ]),
    "soft leather": ([
        "type": "armor",
        "subtype": "light armor",
        "skill to craft": 5,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/armor/craftLeatherArmor.c":(["type":"research"]),
            "leatherworking": (["type":"skill", "value": 3]),
            "armorer": (["type":"skill", "value": 2]),
        ]),
        "crafting materials": ([
            "leather": 10,
            "textile": 2
        ]),
        "skill to use": "soft leather",
        "default ac": 2,
        "default location": Armor,
        "default encumberance": 5,
        "default weight": 3,
        "default material": "leather",
        "default value": 100,
        "default description": ""
    ]),
    "leather jacket": ([
        "type": "armor",
        "subtype": "light armor",
        "skill to craft": 8,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/armor/craftLeatherArmor.c":(["type":"research"]),
            "leatherworking": (["type":"skill", "value": 5]),
            "armorer": (["type":"skill", "value": 3]),
        ]),
        "crafting materials": ([
            "leather": 8,
            "textile": 2
        ]),
        "skill to use": "soft leather",
        "default ac": 1,
        "default location": Armor | ArmGreaves,
        "default encumberance": 5,
        "default weight": 3,
        "default material": "leather",
        "default value": 100,
        "default description": ""
    ]),
    "padded armor": ([
        "type": "armor",
        "subtype": "light armor",
        "skill to craft": 5,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/armor/craftClothing.c":(["type":"research"]),
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
        "default description": ""
    ]),
    "ring mail": ([
        "type": "armor",
        "subtype": "medium armor",
        "skill to craft": 10,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/armor/craftChainmail.c":(["type":"research"]),
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
        "default description": ""
    ]),
   "gloves": ([
        "type": "armor",
        "subtype": "accessory",
        "skill to craft": 5,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/armor/craftGloves.c":(["type":"research"]),
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
        "default description": ""
    ]),
   "gauntlets": ([
        "type": "armor",
        "subtype": "accessory",
        "skill to craft": 7,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/armor/craftGloves.c":(["type":"research"]),
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
        "default description": ""
    ]),
    "helmet": ([
        "type": "armor",
        "subtype": "accessory",
        "skill to craft": 5,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/armor/craftHelmet.c":(["type":"research"]),
            "metal crafting": (["type":"skill", "value": 5]),
        ]),
        "crafting materials": ([
            "metal": 2,
            "leather": 1
        ]),
        "default location": Helmet,
        "default ac": 1,
        "default encumberance": 1,
        "default weight": 1,
        "default material": "iron",
        "default value": 50,
        "default description": ""
    ]),
    "helm": ([
        "type": "armor",
        "subtype": "accessory",
        "skill to craft": 5,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/armor/craftHelmet.c":(["type":"research"]),
            "metal crafting": (["type":"skill", "value": 5]),
        ]),
        "crafting materials": ([
            "metal": 3,
            "leather": 1
        ]),
        "default location": Helmet,
        "default ac": 1,
        "default encumberance": 1,
        "default weight": 1,
        "default material": "iron",
        "default value": 50,
        "default description": ""
    ]),
    "coif": ([
        "type": "armor",
        "subtype": "accessory",
        "skill to craft": 10,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/armor/craftHelmet.c":(["type":"research"]),
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
        "default description": ""
    ]),
    "circlet": ([
        "type": "armor",
        "subtype": "accessory",
        "skill to craft": 10,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/armor/craftJewelry.c":(["type":"research"]),
            "metal crafting": (["type":"skill", "value": 8]),
            "gem crafting": (["type":"skill", "value": 2]),
        ]),
        "crafting materials": ([
            "metal": 2,
            "crystal": 1
        ]),
        "default location": Helmet,
        "default ac": 0,
        "default encumberance": 1,
        "default weight": 1,
        "default material": "silver",
        "default value": 350,
        "default description": ""
    ]),
    "diadem": ([
        "type": "armor",
        "subtype": "accessory",
        "skill to craft": 10,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/armor/craftJewelry.c":(["type":"research"]),
            "metal crafting": (["type":"skill", "value": 8]),
            "gem crafting": (["type":"skill", "value": 2]),
        ]),
        "crafting materials": ([
            "metal": 2,
            "crystal": 1
        ]),
        "default location": Helmet,
        "default ac": 0,
        "default encumberance": 1,
        "default weight": 1,
        "default material": "silver",
        "default value": 350,
        "default description": ""
    ]),
    "tiara": ([
        "type": "armor",
        "subtype": "accessory",
        "skill to craft": 10,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/armor/craftJewelry.c":(["type":"research"]),
            "metal crafting": (["type":"skill", "value": 8]),
            "gem crafting": (["type":"skill", "value": 2]),
        ]),
        "crafting materials": ([
            "metal": 2,
            "crystal": 1
        ]),
        "default location": Helmet,
        "default ac": 0,
        "default encumberance": 1,
        "default weight": 1,
        "default material": "silver",
        "default value": 350,
        "default description": ""
    ]),
    "crown": ([
        "type": "armor",
        "subtype": "accessory",
        "skill to craft": 10,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/armor/craftJewelry.c":(["type":"research"]),
            "metal crafting": (["type":"skill", "value": 8]),
            "gem crafting": (["type":"skill", "value": 2]),
        ]),
        "crafting materials": ([
            "metal": 3,
            "crystal": 2
        ]),
        "default location": Helmet,
        "default ac": 0,
        "default encumberance": 1,
        "default weight": 1,
        "default material": "silver",
        "default value": 350,
        "default description": ""
    ]),
    "hat": ([
        "type": "armor",
        "subtype": "accessory",
        "skill to craft": 5,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/armor/craftClothing.c":(["type":"research"]),
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
        "default description": ""
    ]),
    "boots": ([
        "type": "armor",
        "subtype": "accessory",
        "skill to craft": 5,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/armor/craftClothing.c":(["type":"research"]),
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
        "default description": ""
    ]),
    "shoes": ([
        "type": "armor",
        "subtype": "accessory",
        "skill to craft": 5,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/armor/craftClothing.c":(["type":"research"]),
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
        "default description": ""
    ]),
    "sandals": ([
        "type": "armor",
        "subtype": "accessory",
        "skill to craft": 5,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/armor/craftClothing.c":(["type":"research"]),
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
        "default description": ""
    ]),
    "sabaton": ([
        "type": "armor",
        "subtype": "accessory",
        "skill to craft": 10,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/armor/craftClothing.c":(["type":"research"]),
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
        "default description": ""
    ]),
    "ring": ([
        "type": "armor",
        "subtype": "accessory",
        "skill to craft": 5,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/armor/craftJewelry.c":(["type":"research"]),
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
        "default description": ""
    ]),
    "cloak": ([
        "type": "armor",
        "subtype": "clothing",
        "skill to craft": 5,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/armor/craftClothing.c":(["type":"research"]),
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
        "default description": ""
    ]),
    "amulet": ([
        "type": "armor",
        "subtype": "accessory",
        "skill to craft": 10,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/armor/craftJewelry.c":(["type":"research"]),
            "metal crafting": (["type":"skill", "value": 5]),
            "gem crafting": (["type":"skill", "value": 5]),
        ]),
        "crafting materials": ([
            "metal": 1,
            "crystal": 1
        ]),
        "default location": Amulet,
        "default encumberance": 1,
        "default material": "iron",
        "default value": 75,
        "default description": ""
    ]),
    "necklace": ([
        "type": "armor",
        "subtype": "accessory",
        "skill to craft": 10,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/armor/craftJewelry.c":(["type":"research"]),
            "metal crafting": (["type":"skill", "value": 5]),
            "gem crafting": (["type":"skill", "value": 5]),
        ]),
        "crafting materials": ([
            "metal": 1,
            "crystal": 1
        ]),
        "default location": Amulet,
        "default encumberance": 1,
        "default material": "silver",
        "default value": 125,
        "default description": ""
    ]),
    "belt": ([
        "type": "armor",
        "subtype": "accessory",
        "skill to craft": 5,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/armor/craftClothing.c":(["type":"research"]),
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
        "default description": ""
    ]),
    "sash": ([
        "type": "armor",
        "subtype": "accessory",
        "skill to craft": 5,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/armor/craftClothing.c":(["type":"research"]),
            "sewing": (["type":"skill", "value": 1]),
            "weaving and beadwork": (["type":"skill", "value": 4]),
        ]),
        "crafting materials": ([
            "textile": 4
        ]),
        "default location": Belt,
        "default encumberance": 1,
        "default weight": 1,
        "default material": "leather",
        "default value": 25,
        "default description": ""
    ]),
    "padded arm greaves": ([
        "type":"armor",
        "subtype" : "light armor",
        "skill to craft" : 5,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/armor/craftClothing.c":(["type":"research"]),
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
        "default description" : ""
    ]),
    "padded leg greaves": ([
        "type": "armor",
        "subtype": "light armor",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/armor/craftClothing.c":(["type":"research"]),
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
        "default description": ""
    ]),
    "leather arm greaves": ([
        "type":"armor",
        "subtype" : "light armor",
        "skill to craft" : 5,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/armor/craftLeatherArmor.c":(["type":"research"]),
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
        "default description" : ""
    ]),
    "leather leg greaves": ([
        "type": "armor",
        "subtype": "light armor",
        "skill to craft": 5,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/armor/craftLeatherArmor.c":(["type":"research"]),
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
        "default description": ""
    ]),
    "plate arm greaves": ([
        "type":"armor",
        "subtype" : "heavy armor",
        "skill to craft" : 5,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/armor/craftPlateArmor.c":(["type":"research"]),
            "metal crafting": (["type":"skill", "value": 5]),
        ]),
        "crafting materials": ([
            "metal": 4
        ]),
        "default ac": 2,
        "default location" : ArmGreaves,
        "default encumberance" : 2,
        "default weight" : 2,
        "default material" : "iron",
        "default value" : 75,
        "default description" : ""
    ]),
    "plate leg greaves": ([
        "type": "armor",
        "subtype": "heavy armor",
        "skill to craft": 5,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/armor/craftPlateArmor.c":(["type":"research"]),
            "metal crafting": (["type":"skill", "value": 5]),
        ]),
        "crafting materials": ([
            "metal": 4
        ]),
        "default ac": 2,
        "default location": LegGreaves,
        "default encumberance": 2,
        "default weight": 2,
        "default material": "iron",
        "default value": 75,
        "default description": ""
    ]),
    "bracers": ([
        "type": "armor",
        "subtype": "accessory",
        "skill to craft": 15,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/armor/craftJewelry.c":(["type":"research"]),
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
        "default description": ""
    ])
]);
