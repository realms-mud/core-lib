##### Guilds
TBD

#### Guild File

[Creating research and research trees is discussed here.](research.md)

### API

`guildName(string name)`

`addPreferredSkillType(string type)`

`addRank(string name, mapping data)`

`setDefaultRank(string rankName)`

`prohibitedGuildCombinations(string *prohibitedGuilds)`

`addCriteria(string name, mapping data)`

//  criteria mapping will be sparsely populated
//  "<item>": ([
//      "type": skill|research|research tree|modifier|trait|points|attack|research choice
//      "apply": "<#> every [<#>] level[s]|at level #|at rank #",
//      "begin at level": <level>,   // all begin/end criteria MUST match
//      "end at level": <level>,     // in order to have <item> applied
//      "begin at rank": <rank>,
//      "end at rank": <rank>,
//      "begin when researched": <research>
//  ]),
//  Examples:
//  "hit points": ([
//      "type": "modifier",
//      "apply": "5 every level",
//  ]),
//  "attribute points": ([
//      "type": "attribute points",   // meaning spendable points on any attribute
//      "apply": "1 every level"
//  ]),
//  "skill points": ([
//      "type": "skill points",
//      "apply": "3 every level",
//  ]),
//  "research points": ([
//      "type": "research points",
//      "apply": "1 every level",
//  ]),
//  "long sword": ([
//      "type": "skill",
//      "apply": "1 every 2 levels",
//      "begin at level": 3,
//      "end at level": 10
//  ]),
//  "fireball": ([
//      "type": "research",
//      "research object": "<path and file name>",
//      "apply": "at level 10",
//  ]),
//  "inquisitive": ([
//      "type": "trait",
//      "trait object": "<path and file name>",
//      "apply": "at rank archmage"
//  ]),
//  "elemental fire": ([
//      "type": "research tree",
//      "research tree": "<path and file name>",
//      "apply": "at level 5"
//   ]),
//  "magic path": ([
//      "type": "research path",
//      "name": "Magic choice",
//      "description": "...",
//      "research objects": ({ "<path and file name>", "<another>", ... }),
//      "apply": "at level 5"
//   ]),
//  "magic choice": ([
//      "type": "research choice",
//      "name": "Magic choice",
//      "description": "...",
//      "research objects": ({ "<path and file name>", "<another>", ... }),
//      "apply": "at level 5"
//   ]),
//  "fireball enhancement": ([
//      "type": "research",
//      "research object": "<path and file name>",
//      "apply": "at level 15"
//      "apply if chosen": ({ "<research or tree>" })
//   ]),
//  "weapon attack": ([
//      "type": "attack",
//      "apply": "1 every 15 levels,
//      "begin at level": 10,
//      "begin at rank": "corporal"
//  ]),
//  "fire attack": ([
//      "type": "attack",
//      "base damage": 25,
//      "apply": "1 every 15 levels,
//      "begin at level": 10,
//      "begin at rank": "corporal"
//  ])

