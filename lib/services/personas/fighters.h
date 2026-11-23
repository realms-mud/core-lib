private nosave mapping fighterBlueprints = ([
    "swordsman":([
        "description": "A swordsman stands tall and poised, clad in well-fitted armor that "
            "gleams with polish. Their hands are calloused, and their posture is "
            "confident, with a sword always at their side. Their gaze is sharp, and "
            "their movements are precise and measured.",
        "category": "fighters",
        "is humanoid": 1,
        "primary skills": ({ "parry", "dodge", "shield", "long sword",
            "hand and a half sword", "short sword", "dagger",
            "two-handed sword", "plate armor", "splint armor",
            "chainmail", "scalemail", "hard leather", "soft leather",
            "no armor" }),
        "secondary skills": ({ "anatomy and physiology", "perception",
            "listen", "spot", "common", "dual wield" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "fighter" }),
        "equipment": ([ 
            "weapons":({ "swords" }),
            "armor": ({ "light-armor", "medium-armor", "heavy-armor" }),
            "armor/accessories": ({ "belt", "boots", "coif", "gauntlets", "gloves", 
                "helm", "helmet", "ring", "sabaton" })
        ]),
        "base hit points": 100,
        "base spell points": 10,
        "base stamina points": 50
    ]),
    "man-at-arms":([
        "description": "A man-at-arms is broad-shouldered and sturdy, wearing a mix of "
            "chainmail and plate. Their armor is practical and well-worn, often "
            "bearing the marks of many battles. They carry a variety of weapons, and "
            "their face is often set in a determined expression.",
        "category": "fighters",
        "is humanoid": 1,
        "primary skills": ({ "parry", "dodge", "shield", "long sword",
            "hand and a half sword", "short sword", "dagger", "axe",
            "two-handed sword", "plate armor", "splint armor", "mace",
            "chainmail", "scalemail", "hard leather", "soft leather",
            "no armor" }),
        "secondary skills": ({ "anatomy and physiology", "perception",
            "listen", "spot", "common", "dual wield" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "fighter" }),
        "equipment": ([ 
            "weapons":({ "swords", "axes", "maces" }),
            "armor": ({ "light-armor", "medium-armor", "heavy-armor" }),
            "armor/accessories": ({ "belt", "boots", "coif", "gauntlets", "gloves", 
                "helm", "helmet", "ring", "sabaton" })
        ]),
        "base hit points": 150,
        "base spell points": 10,
        "base stamina points": 75
    ]),
    "knifeman":([
        "description": "A knifeman is lean and agile, dressed in close-fitting leathers or "
            "light mail. Several daggers are strapped to their belt and boots, and "
            "their eyes dart about with a wary, calculating look. Their hands are "
            "quick, and their stance is always ready to spring into action.",
        "category": "fighters",
        "is humanoid": 1,
        "primary skills": ({ "parry", "dodge", "shield", "short sword", "dagger",
            "chainmail", "scalemail", "hard leather", "soft leather",
            "no armor" }),
        "secondary skills": ({ "anatomy and physiology", "perception",
            "listen", "spot", "common", "dual wield" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "fighter" }),
        "equipment": ([ 
            "weapons":({ "daggers" }),
            "armor": ({ "light-armor", "medium-armor" }),
            "armor/accessories": ({ "belt", "boots", "coif", "gloves", 
                "helmet", "ring", "sabaton" })
        ]),
        "base hit points": 100,
        "base spell points": 10,
        "base stamina points": 50
    ]),
    "light infantry": ([
        "description": "Light infantry wear supple leather or simple mail, allowing for "
            "freedom of movement. Their gear is practical and minimal, and their "
            "faces are often sun-browned and alert. They carry swords or daggers, "
            "and their boots are worn from long marches.",
        "category": "fighters",
        "is humanoid": 1,
        "primary skills": ({ "parry", "dodge", "shield", "long sword",
            "hand and a half sword", "short sword", "dagger",
            "two-handed sword", "hard leather", "soft leather",
            "no armor" }),
        "secondary skills": ({ "anatomy and physiology", "perception",
            "listen", "spot", "common", "dual wield" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "fighter", "infantry" }),
        "equipment": ([ 
            "weapons":({ "daggers", "swords" }),
            "armor": ({ "light-armor" }),
            "armor/accessories": ({ "belt", "boots", "coif", "gloves", 
                "helmet", "ring" })
        ]),
        "base hit points": 100,
        "base spell points": 10,
        "base stamina points": 50
    ]),
    "axeman":([
        "description": "An axeman is powerfully built, with muscular arms and a heavy axe "
            "resting on one shoulder. Their armor is reinforced and often bears "
            "nicks and scars from battle. Their beard may be thick, and their hands "
            "are large and calloused.",
        "category": "fighters",
        "is humanoid": 1,
        "primary skills": ({ "parry", "dodge", "shield", "axe", 
            "plate armor", "splint armor",
            "chainmail", "scalemail", "hard leather", "soft leather",
            "no armor" }),
        "secondary skills": ({ "anatomy and physiology", "perception",
            "listen", "spot", "common", "dual wield" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "fighter" }),
        "equipment": ([ 
            "weapons":({ "axes" }),
            "armor": ({ "medium-armor", "heavy-armor" }),
            "armor/accessories": ({ "belt", "boots", "coif", "gauntlets", "gloves", 
                "helm", "helmet", "ring", "sabaton" })
        ]),
        "base hit points": 100,
        "base spell points": 10,
        "base stamina points": 50
    ]),
    "maceman":([
        "description": "A maceman is stocky and solid, clad in sturdy armor with a heavy "
            "mace hanging from their belt. Their arms are thick, and their knuckles "
            "are often bruised. Their helmet is dented, and their expression is "
            "grim and resolute.",
        "category": "fighters",
        "is humanoid": 1,
        "primary skills": ({ "parry", "dodge", "shield", "mace", 
            "plate armor", "splint armor",
            "chainmail", "scalemail", "hard leather", "soft leather",
            "no armor" }),
        "secondary skills": ({ "anatomy and physiology", "perception",
            "listen", "spot", "common", "dual wield" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "fighter" }),
        "equipment": ([ 
            "weapons":({ "maces" }),
            "armor": ({ "light-armor", "medium-armor", "heavy-armor" }),
            "armor/accessories": ({ "belt", "boots", "coif", "gauntlets", "gloves", 
                "helm", "helmet", "ring", "sabaton" })
        ]),
        "base hit points": 100,
        "base spell points": 10,
        "base stamina points": 50
    ]),
    "hammerman":([
        "description": "A hammerman is broad and imposing, with a massive warhammer slung "
            "across their back. Their armor is reinforced at the shoulders and arms, "
            "and their boots are heavy. Their jaw is set, and their eyes are steely "
            "with focus.",
        "category": "fighters",
        "is humanoid": 1,
        "primary skills": ({ "parry", "dodge", "shield", "hammer", 
            "plate armor", "splint armor",
            "chainmail", "scalemail", "hard leather", "soft leather",
            "no armor" }),
        "secondary skills": ({ "anatomy and physiology", "perception",
            "listen", "spot", "common", "dual wield" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "fighter" }),
        "equipment": ([ 
            "weapons":({ "hammers" }),
            "armor": ({ "light-armor", "medium-armor", "heavy-armor" }),
            "armor/accessories": ({ "belt", "boots", "coif", "gauntlets", "gloves", 
                "helm", "helmet", "ring", "sabaton" })
        ]),
        "base hit points": 100,
        "base spell points": 10,
        "base stamina points": 50
    ]),
    "flail man":([
        "description": "A flail man is clad in heavy armor, with a spiked flail hanging "
            "from their belt. Their gauntlets are reinforced, and their helmet is "
            "often adorned with a crest. Their stance is balanced, and their eyes "
            "watch for any opening.",
        "category": "fighters",
        "is humanoid": 1,
        "primary skills": ({ "parry", "dodge", "shield", "flail", 
            "plate armor", "splint armor",
            "chainmail", "scalemail", "hard leather", "soft leather",
            "no armor" }),
        "secondary skills": ({ "anatomy and physiology", "perception",
            "listen", "spot", "common", "dual wield" }),
        "traits": ({ }),
        "aliases": ({ "fighter", "man" }),
        "potential traits": ({ }),
        "equipment": ([ 
            "weapons":({ "flails" }),
            "armor": ({ "light-armor", "medium-armor", "heavy-armor" }),
            "armor/accessories": ({ "belt", "boots", "coif", "gauntlets", "gloves", 
                "helm", "helmet", "ring", "sabaton" })
        ]),
        "base hit points": 100,
        "base spell points": 10,
        "base stamina points": 50
    ]),
    "staff man":([
        "description": "A staff man is tall and wiry, dressed in simple robes or light "
            "armor. They carry a long staff, often carved or adorned, and their "
            "movements are fluid and controlled. Their eyes are calm, and their "
            "stance is relaxed but ready.",
        "category": "fighters",
        "is humanoid": 1,
        "primary skills": ({ "parry", "dodge", "shield", "staff", 
            "plate armor", "splint armor",
            "chainmail", "scalemail", "hard leather", "soft leather",
            "no armor" }),
        "secondary skills": ({ "anatomy and physiology", "perception",
            "listen", "spot", "common", "dual wield" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "fighter", "man" }),
        "equipment": ([ 
            "weapons":({ "staffs" }),
            "armor": ({ "light-armor", "medium-armor" }),
            "armor/accessories": ({ "belt", "boots", "coif", "gauntlets", "gloves", 
                "helmet", "ring", "sabaton" })
        ]),
        "base hit points": 100,
        "base spell points": 10,
        "base stamina points": 50
    ]),
    "halberdier":([
        "description": "A halberdier is tall and disciplined, clad in heavy armor with a "
            "long halberd held upright. Their armor is polished, and their helmet "
            "often sports a plume. Their posture is straight, and their gaze is "
            "forward and unwavering.",
        "category": "fighters",
        "is humanoid": 1,
        "primary skills": ({ "parry", "dodge", "pole arm", 
            "plate armor", "splint armor", "chainmail", "scalemail" }),
        "secondary skills": ({ "anatomy and physiology", "perception",
            "listen", "spot", "common" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "fighter" }),
        "equipment": ([ 
            "weapons":({ "pole-arms/halberd" }),
            "armor": ({ "heavy-armor" }),
            "armor/accessories": ({ "belt", "boots", "coif", "gauntlets", "gloves", 
                "helm", "helmet", "ring", "sabaton" })
        ]),
        "base hit points": 100,
        "base spell points": 10,
        "base stamina points": 50
    ]),
    "spearman":([
        "description": "A spearman is lean and athletic, dressed in light or medium armor. "
            "They carry a long spear, and their shield is strapped to one arm. Their "
            "stance is balanced, and their eyes are alert, scanning for threats.",
        "category": "fighters",
        "is humanoid": 1,
        "primary skills": ({ "parry", "dodge", "pole arm", 
            "plate armor", "splint armor",
            "chainmail", "scalemail", "hard leather", "soft leather",
            "no armor" }),
        "secondary skills": ({ "anatomy and physiology", "perception",
            "listen", "spot", "common" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "fighter" }),
        "equipment": ([ 
            "weapons":({ "pole-arms/spear" }),
            "armor": ({ "light-armor", "medium-armor" }),
            "armor/accessories": ({ "belt", "boots", "coif", "gauntlets", "gloves", 
                "helmet", "ring" })
        ]),
        "base hit points": 100,
        "base spell points": 10,
        "base stamina points": 50
    ]),
    "guisarmier":([
        "description": "A guisarmier is tall and imposing, clad in a mix of mail and plate. "
            "They wield a long polearm with a hooked blade, and their armor is "
            "decorated with insignia. Their stance is disciplined, and their eyes are "
            "focused on the battlefield.",
        "category": "fighters",
        "is humanoid": 1,
        "primary skills": ({ "parry", "dodge", "pole arm", 
            "plate armor", "splint armor",
            "chainmail", "scalemail", "hard leather", "soft leather",
            "no armor" }),
        "secondary skills": ({ "anatomy and physiology", "perception",
            "listen", "spot", "common" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "fighter" }),
        "equipment": ([ 
            "weapons":({ "pole-arms" }),
            "armor": ({ "light-armor", "medium-armor", "heavy-armor" }),
            "armor/accessories": ({ "belt", "boots", "coif", "gauntlets", "gloves", 
                "helm", "helmet", "ring", "sabaton" })
        ]),
        "base hit points": 100,
        "base spell points": 10,
        "base stamina points": 50
    ]),
    "brawler":([
        "description": "A brawler is rugged and muscular, often bare-armed or wearing only "
            "simple armor. Their knuckles are scarred, and their nose may be crooked "
            "from old breaks. Their stance is loose and ready, with a confident grin.",
        "category": "fighters",
        "is humanoid": 1,
        "primary skills": ({ "parry", "dodge", "unarmed", 
            "plate armor", "splint armor",
            "chainmail", "scalemail", "hard leather", "soft leather",
            "no armor" }),
        "secondary skills": ({ "anatomy and physiology", "perception",
            "listen", "spot", "common" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "fighter" }),
        "equipment": ([
            "armor": ({ "light-armor", "medium-armor" }),
            "armor/accessories": ({ "belt", "boots", "coif", "gauntlets", "gloves", 
                "helm", "helmet", "ring", "sabaton" })
        ]),
        "base hit points": 100,
        "base spell points": 10,
        "base stamina points": 50
    ]),
    "archer":([
        "description": "An archer is slender and keen-eyed, dressed in light armor or "
            "leathers. A quiver of arrows is slung across their back, and a bow is "
            "always within reach. Their fingers are calloused, and their gaze is "
            "focused on distant targets.",
        "category": "fighters",
        "is humanoid": 1,
        "primary skills": ({ "parry", "dodge", "shield", "bow", 
            "plate armor", "splint armor",
            "chainmail", "scalemail", "hard leather", "soft leather",
            "no armor" }),
        "secondary skills": ({ "anatomy and physiology", "perception",
            "listen", "spot", "common", "bowyer and fletcher" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "fighter" }),
        "equipment": ([ 
            "weapons":({ "bows" }),
            "armor": ({ "light-armor", "medium-armor" }),
            "armor/accessories": ({ "belt", "boots", "coif", "gloves", 
                "helmet", "ring" })
        ]),
        "base hit points": 100,
        "base spell points": 10,
        "base stamina points": 50
    ]),
    "crossbowman":([
        "description": "A crossbowman is sturdy and practical, wearing medium armor and "
            "carrying a heavy crossbow. Their belt is lined with bolts, and their "
            "hands are strong and steady. Their eyes are narrowed, always searching "
            "for a vantage point.",
        "category": "fighters",
        "is humanoid": 1,
        "primary skills": ({ "parry", "dodge", "shield", "crossbow", 
            "plate armor", "splint armor",
            "chainmail", "scalemail", "hard leather", "soft leather",
            "no armor" }),
        "secondary skills": ({ "anatomy and physiology", "perception",
            "listen", "spot", "common", "bowyer and fletcher" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "fighter" }),
        "equipment": ([ 
            "weapons":({ "crossbows" }),
            "armor": ({ "light-armor", "medium-armor" }),
            "armor/accessories": ({ "belt", "boots", "coif", "gloves", 
                "helmet", "ring" })
        ]),
        "base hit points": 100,
        "base spell points": 10,
        "base stamina points": 50
    ]),
    "auxiliary":([
        "description": "An auxiliary is lightly armored, with a sling or throwing weapons "
            "at their side. Their clothing is practical, and their boots are worn "
            "from travel. They have a ready, alert look and move with quick, "
            "efficient motions.",
        "category": "fighters",
        "is humanoid": 1,
        "primary skills": ({ "parry", "dodge", "shield", "sling", 
            "thrown", "plate armor", "splint armor",
            "chainmail", "scalemail", "hard leather", "soft leather",
            "no armor" }),
        "secondary skills": ({ "anatomy and physiology", "perception",
            "listen", "spot", "common", "bowyer and fletcher" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "fighter" }),
        "equipment": ([ 
            "weapons":({ "thrown", "slings" }),
            "armor": ({ "light-armor", "medium-armor" }),
            "armor/accessories": ({ "belt", "boots", "coif", "gloves", 
                "helmet", "ring" })
        ]),
        "base hit points": 100,
        "base spell points": 10,
        "base stamina points": 50
    ]),
    "knight": ([
        "description": "A knight is imposing and regal, clad in gleaming plate armor "
            "adorned with heraldic symbols. Their helmet is crested, and their "
            "posture is upright and proud. A sword or mace hangs at their side, and "
            "their cloak is often trimmed with fine embroidery.",
        "category": "fighters",
        "is humanoid": 1,
        "primary skills": ({ "parry", "dodge", "shield", "long sword",
            "hand and a half sword", "short sword", "dagger", "axe",
            "two-handed sword", "plate armor", "splint armor", "mace",
            "chainmail", "scalemail", "hard leather", "soft leather",
            "no armor" }),
        "secondary skills": ({ "anatomy and physiology", "perception",
            "listen", "spot", "common", "dual wield" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "fighter" }),
        "equipment": ([ 
            "weapons":({ "swords", "axes", "maces" }),
            "armor": ({ "medium-armor", "heavy-armor" }),
            "armor/accessories": ({ "belt", "boots", "coif", "gauntlets", "gloves", 
                "helm", "helmet", "ring", "sabaton" })
        ]),
        "base hit points": 150,
        "base spell points": 100,
        "base stamina points": 50
    ]),
    "phaedra": ([
        "description": "A phaedra is a striking figure in ornate, masterfully crafted armor. "
            "Their cloak is richly colored, and their helm is adorned with intricate "
            "designs. Their bearing is noble, and their eyes reflect both wisdom and "
            "resolve.",
        "category": "fighters",
        "is humanoid": 1,
        "primary skills": ({ "parry", "dodge", "shield", "long sword",
            "hand and a half sword", "short sword", "dagger", "axe",
            "two-handed sword", "plate armor", "splint armor", "mace",
            "chainmail", "scalemail", "hard leather", "soft leather",
            "no armor" }),
        "secondary skills": ({ "anatomy and physiology", "perception",
            "listen", "spot", "common", "dual wield" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "fighter", "knight" }),
        "equipment": ([ 
            "weapons":({ "swords", "axes", "maces" }),
            "armor": ({ "medium-armor", "heavy-armor" }),
            "armor/accessories": ({ "belt", "boots", "coif", "gauntlets", "gloves", 
                "helm", "helmet", "ring", "sabaton" })
        ]),
        "base hit points": 200,
        "base spell points": 100,
        "base stamina points": 100
    ]),
    "knight of the storm":([
        "description": "A knight of the storm is clad in armor etched with swirling "
            "patterns, often accented with blue or silver. Their cloak billows as if "
            "caught in a breeze, and their eyes flash with intensity. Their presence "
            "is commanding, and their armor gleams with a faint, electric sheen.",
        "category": "fighters",
        "is humanoid": 1,
        "primary skills": ({ "parry", "dodge", "shield", "long sword",
            "hand and a half sword", "short sword", "dagger",
            "two-handed sword", "plate armor", "splint armor",
            "chainmail", "scalemail", "elemental air" }),
        "secondary skills": ({ "anatomy and physiology", "perception",
            "listen", "spot", "common", "dual wield", "magical essence",
            "spellcraft", "evocation" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "fighter", "knight", "storm" }),
        "equipment": ([ 
            "weapons":({ "swords" }),
            "armor": ({ "medium-armor", "heavy-armor" }),
            "armor/accessories": ({ "belt", "boots", "coif", "gauntlets", "gloves", 
                "helm", "helmet", "ring", "sabaton" })
        ]),
        "research": ([
            "lightning": 1,
        ]),
        "base hit points": 150,
        "base spell points": 100,
        "base stamina points": 50
    ]),
    "bard": ([
        "description": "Bards are quick-witted performers, equally at ease in a crowded "
            "tavern and a dangerous skirmish. Their instruments and voices carry "
            "stories, taunts, and stirring refrains that unsettle their foes.",
        "category": "fighters",
        "is humanoid": 1,
        "primary skills": ({ "short sword", "dagger", "no armor", "spellcraft",
            "magical essence", "dodge", "parry" }),
        "secondary skills": ({ "perception", "listen", "spot", "common",
            "reading", "anatomy and physiology", "persuasion" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "bard", "skald", "minstrel" }),
        "equipment": ([
            "weapons": ({ "swords", "daggers" }),
            "armor/clothing": ({ "robes", "leathers" }),
            "armor/accessories": ({ "boots", "gloves", "ring", "amulet" })
        ]),
        "attacks": ([ "sonic": 15 ]),
        "research": ([
            "battle melody": 1,
            "dissonant chord": 10,
            "anthem of courage": 15
        ]),
        "base hit points": 80,
        "base spell points": 80,
        "base stamina points": 60
    ]),
    "rogue": ([
        "description": "Rogues favor speed, caution, and unfair advantages. They move "
            "quietly, watch every opening, and carry the light weapons needed to "
            "strike before an opponent can react.",
        "category": "fighters",
        "is humanoid": 1,
        "primary skills": ({ "dagger", "short sword", "no armor", "dodge",
            "parry", "dual wield" }),
        "secondary skills": ({ "perception", "listen", "spot", "common",
            "reading", "anatomy and physiology", "short sword" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "rogue", "thief" }),
        "equipment": ([
            "weapons": ({ "daggers", "swords" }),
            "armor": ({ "light-armor" }),
            "armor/accessories": ({ "belt", "boots", "gloves", "ring" })
        ]),
        "attacks": ([ "physical": 20 ]),
        "research": ([
            "cheap shot": 1,
            "crippling strike": 10,
            "lethal opening": 15
        ]),
        "base hit points": 80,
        "base spell points": 40,
        "base stamina points": 80
    ]),
    "monk": ([
        "description": "Monks are disciplined martial artists whose calm movements hide "
            "explosive speed. Their training turns empty hands into formidable "
            "weapons and lets them withstand blows that would stagger others.",
        "category": "fighters",
        "is humanoid": 1,
        "primary skills": ({ "unarmed", "parry", "dodge", "no armor", "staff",
            "body", "spirit", "transformation" }),
        "secondary skills": ({ "perception", "listen", "spot", "common",
            "reading", "anatomy and physiology" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "monk", "martial artist" }),
        "equipment": ([
            "weapons": ({ "staffs" }),
            "armor/clothing": ({ "robes" }),
            "armor/accessories": ({ "boots", "gloves", "amulet" })
        ]),
        "attacks": ([ "bludgeon": 20 ]),
        "research": ([
            "palm strike": 1,
            "chi burst": 10,
            "hundred strikes": 15
        ]),
        "base hit points": 90,
        "base spell points": 60,
        "base stamina points": 70
    ]),
    "ranger": ([
        "description": "Rangers are self-reliant scouts who know the wilds as well as "
            "their own weapons. They watch the land for danger, strike from range, "
            "and adapt quickly when a fight closes in.",
        "category": "fighters",
        "is humanoid": 1,
        "primary skills": ({ "bow", "dagger", "short sword", "dodge",
            "hard leather", "no armor", "animal", "plant", "perception" }),
        "secondary skills": ({ "parry", "listen", "spot", "common", "reading",
            "anatomy and physiology", "elemental earth", "elemental water" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "ranger", "scout", "warden" }),
        "equipment": ([
            "weapons": ({ "bows", "daggers", "swords" }),
            "armor": ({ "light-armor", "medium-armor" }),
            "armor/accessories": ({ "belt", "boots", "gloves", "ring" })
        ]),
        "attacks": ([ "arrow": 20 ]),
        "research": ([
            "aimed shot": 1,
            "elemental arrow": 10,
            "hunters volley": 15
        ]),
        "base hit points": 100,
        "base spell points": 40,
        "base stamina points": 70
    ]),
    "runeskald": ([
        "description": "Runeskalds carve ancient power into runes and carry their "
            "ancestral songs into battle. Their magic is rough and immediate, "
            "shaping weapon strikes with elemental and spiritual force.",
        "category": "fighters",
        "is humanoid": 1,
        "primary skills": ({ "axe", "hammer", "staff", "no armor", "spellcraft",
            "magical essence", "war", "body", "spirit" }),
        "secondary skills": ({ "parry", "dodge", "perception", "listen", "spot",
            "common", "reading", "elemental earth", "elemental fire" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "runeskald", "rune warrior", "skald" }),
        "equipment": ([
            "weapons": ({ "axes", "hammers", "staffs" }),
            "armor": ({ "light-armor", "medium-armor" }),
            "armor/accessories": ({ "belt", "boots", "gloves", "amulet" })
        ]),
        "attacks": ([ "cold": 20 ]),
        "research": ([
            "rune strike": 1,
            "frostfire glyph": 10,
            "world rune blast": 15
        ]),
        "base hit points": 100,
        "base spell points": 80,
        "base stamina points": 70
    ]),
    "league of assassins": ([
        "description": "Assassins of the League are patient and exacting, concealing "
            "their intentions until a single opening is enough. They favor light "
            "blades, careful footwork, and decisive attacks.",
        "category": "fighters",
        "is humanoid": 1,
        "primary skills": ({ "dagger", "short sword", "no armor", "dodge",
            "parry", "dual wield" }),
        "secondary skills": ({ "perception", "listen", "spot", "common",
            "reading", "anatomy and physiology" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "assassin", "league assassin" }),
        "equipment": ([
            "weapons": ({ "daggers", "swords" }),
            "armor": ({ "light-armor" }),
            "armor/accessories": ({ "belt", "boots", "gloves", "ring" })
        ]),
        "attacks": ([ "poison": 20 ]),
        "research": ([
            "assassin mark": 1,
            "shadow strike": 10,
            "silent execution": 15
        ]),
        "base hit points": 70,
        "base spell points": 40,
        "base stamina points": 90
    ]),
    "drambor edlothiad": ([
        "description": "Blade singers of the Drambor Edlothiad weave elven sorcery "
            "through precise swordplay. They are swift and composed, turning a "
            "well-timed cut into an extension of their magic.",
        "category": "fighters",
        "is humanoid": 1,
        "primary skills": ({ "long sword", "hand and a half sword", "no armor",
            "spellcraft", "evocation", "magical essence", "parry", "dodge" }),
        "secondary skills": ({ "perception", "listen", "spot", "common",
            "reading", "elemental air", "transformation", "manipulation" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "blade singer", "spell sword", "elven warrior mage" }),
        "equipment": ([
            "weapons": ({ "swords" }),
            "armor": ({ "light-armor" }),
            "armor/accessories": ({ "bracers", "boots", "gloves", "ring" })
        ]),
        "attacks": ([ "magical": 20 ]),
        "research": ([
            "spellblade strike": 1,
            "arcane edge": 10,
            "blade song": 15
        ]),
        "base hit points": 100,
        "base spell points": 100,
        "base stamina points": 60
    ]),
    "scion of dhuras": ([
        "description": "Scions of Dhuras channel elemental power through a weapon of "
            "their choosing. They combine disciplined melee technique with "
            "magical force, adapting their attacks to the needs of the fight.",
        "category": "fighters",
        "is humanoid": 1,
        "primary skills": ({ "long sword", "dagger", "axe", "mace", "hammer",
            "staff", "no armor", "spellcraft", "magical essence", "blood",
            "spirit" }),
        "secondary skills": ({ "parry", "dodge", "perception", "listen", "spot",
            "common", "reading", "destruction", "elemental fire" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "scion", "weapon mage" }),
        "equipment": ([
            "weapons": ({ "swords", "daggers", "axes", "maces", "hammers",
                "staffs" }),
            "armor": ({ "light-armor", "medium-armor" }),
            "armor/accessories": ({ "bracers", "boots", "gloves", "ring" })
        ]),
        "attacks": ([ "magical": 20 ]),
        "research": ([
            "charged weapon": 1,
            "avatar strike": 10,
            "dhuras fury": 15
        ]),
        "base hit points": 90,
        "base spell points": 90,
        "base stamina points": 60
    ]),
    "therianthrope": ([
        "description": "Therianthropes carry a bestial strength beneath their humanoid "
            "form. Their movements are restless and predatory, and their natural "
            "weapons make them dangerous at close quarters.",
        "category": "fighters",
        "is humanoid": 1,
        "primary skills": ({ "unarmed", "dodge", "no armor", "transformation",
            "animal", "body", "spirit", "elemental earth" }),
        "secondary skills": ({ "parry", "perception", "listen", "spot", "common",
            "anatomy and physiology", "plant" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "shifter", "beast warrior" }),
        "equipment": ([
            "armor/clothing": ({ "leathers" }),
            "armor/accessories": ({ "amulet", "boots", "gloves" })
        ]),
        "attacks": ([ "physical": 20 ]),
        "research": ([
            "primal claw": 1,
            "predator pounce": 10,
            "primal maul": 15
        ]),
        "base hit points": 110,
        "base spell points": 60,
        "base stamina points": 80
    ]),
    "aegis guard": ([
        "description": "Aegis Guards are disciplined protectors trained to hold a line "
            "under pressure. Their swordplay is measured, their defenses deliberate, "
            "and they answer an opening with a controlled counterstrike.",
        "category": "fighters",
        "is humanoid": 1,
        "primary skills": ({ "long sword", "shield", "parry", "dodge",
            "plate armor", "chainmail", "no armor" }),
        "secondary skills": ({ "perception", "listen", "spot", "common",
            "anatomy and physiology", "short sword", "mace" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "aegis", "guardsman" }),
        "equipment": ([
            "weapons": ({ "swords" }),
            "armor": ({ "medium-armor", "heavy-armor" }),
            "armor/accessories": ({ "belt", "boots", "gauntlets", "helm" })
        ]),
        "attacks": ([ "bludgeon": 20 ]),
        "research": ([
            "shield bash": 1,
            "guardians counter": 10,
            "aegis judgment": 15
        ]),
        "base hit points": 140,
        "base spell points": 40,
        "base stamina points": 70
    ]),
    "werric knight": ([
        "description": "Werric Knights are steadfast warriors who carry the discipline "
            "of the crown into battle. Their armor is practical, their weapons "
            "well-kept, and their courage inspires those who stand beside them.",
        "category": "fighters",
        "is humanoid": 1,
        "primary skills": ({ "long sword", "warhammer", "mace", "shield",
            "parry", "dodge", "plate armor", "chainmail" }),
        "secondary skills": ({ "perception", "listen", "spot", "common",
            "anatomy and physiology", "leadership" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "werric", "crown knight", "knight" }),
        "equipment": ([
            "weapons": ({ "swords", "hammers", "maces" }),
            "armor": ({ "medium-armor", "heavy-armor" }),
            "armor/accessories": ({ "belt", "boots", "gauntlets", "helm",
                "ring" })
        ]),
        "attacks": ([ "bludgeon": 20 ]),
        "research": ([
            "battle charge": 1,
            "werric might": 10,
            "knightly onslaught": 15
        ]),
        "base hit points": 150,
        "base spell points": 30,
        "base stamina points": 80
    ]),
    "guardian of khazurath": ([
        "description": "Guardians of Khazurath are broad, enduring defenders trained "
            "to protect their mountain home. They trust in heavy weapons, "
            "unyielding armor, and the strength of the stone beneath their feet.",
        "category": "fighters",
        "is humanoid": 1,
        "primary skills": ({ "axe", "hammer", "shield", "plate armor",
            "chainmail", "parry", "dodge", "elemental earth" }),
        "secondary skills": ({ "perception", "listen", "spot", "common",
            "anatomy and physiology", "hard leather", "no armor" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "guardian", "dwarven defender" }),
        "equipment": ([
            "weapons": ({ "axes", "hammers" }),
            "armor": ({ "medium-armor", "heavy-armor" }),
            "armor/accessories": ({ "belt", "boots", "gauntlets", "helm" })
        ]),
        "attacks": ([ "earth": 20 ]),
        "research": ([
            "mountain blow": 1,
            "stonebreaker": 10,
            "khazurath fury": 15
        ]),
        "base hit points": 170,
        "base spell points": 20,
        "base stamina points": 80
    ]),
]);
