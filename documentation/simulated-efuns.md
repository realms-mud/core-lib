##### Services
This module provides safe, testable wrappers and shared helpers used across the codebase.  
Key purpose: centralize common efun usage, provide test-mode hooks, and expose a simple service loader.

- `getService(string name)`  
  - Loads and caches `/lib/services/{name}Service.c`. Use this to access system services rather than loading files directly.
  - Example (inline):
    ```
    object cfg = getService("configuration");
    if (cfg) cfg->decorate("Hello", "heading", "quests", "none");
    ```

- Other helpers in the simulated-efuns layer wrap efuns with validation and test-mode overrides: interactive info, object info, users, string helpers, DB helpers (internal), and testing shortcuts.

##### Groups
Groups are the permission/command model for player/wizard roles. Group classes live in `/lib/services/groups/*.c` and inherit `baseGroup.c`.

- Concept
  - Each group defines: a `name`, path-based permissions (Read / Write / Owner), and an allowed wizard command list.
  - Permission flags (from `baseGroup.c`): `Owner = 0x1`, `Write = 0x2`, `Read = 0x4`, `None = 0x0`, plus `Unknown`.

- How permissions work
  - `addPermission("/some/path", Read | Write)` builds a nested mapping keyed by path segments. The lookup walks segments and falls back to `$ANY` or group-level `permissions` where present.
  - Paths support `$USER` and `$ANY` placeholders (e.g., `/players/$USER/closed`, `/p/$ANY/$USER.o`).
  - Public APIs on a group object:
    - `hasReadAccess(object user, string path)` → canonical path or 0
    - `hasWriteAccess(object user, string path)` → canonical path or 0
    - `hasOwnershipAccess(object user, string path)` → boolean
    - `hasExecuteAccess(object user, string command)` → boolean

- Example: create a simple author group (inline)
  ```
  inherit "/lib/services/groups/baseGroup.c";

  protected nomask void applyGroupDetails()
  {
      setName("Author");
      addPermission("/areas/$USER", Read | Write | Owner);
      addCommand("generate");
  }
  ```

- Example usage (inline): check if user can write a path
  ```
  object grp = load_object("/lib/services/groups/wizard.c");
  if (grp && grp->hasWriteAccess(userObj, "/areas/foo"))
  {
      // ok to write
  }
  ```

- Note: Wizards (via creation commands) may create group records through the group service — use the service rather than manipulating group files directly whenever possible.

##### Security — privileged groups (master-level)
The secure/master layer exposes `priviledgeGroup.c` as the master-side base class for master-level permission profiles. These are NOT the same as the in-game group objects and are intended for master/driver checks only.

Key points from `priviledgeGroup.c`:
- Flag bits: `Owner = 0x1`, `Write = 0x2`, `Read = 0x4`, `Unknown = 0x8`, `None = 0x0`.
- Core helpers:
  - `addPermission(string path, int permission)` — builds a nested permissions map keyed by path components.
  - `hasReadAccess(string path)` and `hasWriteAccess(string path)` — return the path when allowed.
  - `addPriviledgedEfun(string command)` — whitelist of privileged efuns/methods that this privileged group allows (only a restrictive set permitted).
  - `allowInheritedPermissions()` and `inheritPermissions(string method)` — support allowing permissions to be applied to callers that inherit this privileged class and the method is permitted.

Important guidance:
- Files that inherit from `priviledgeGroup.c` are master/secure classes. They are consulted by master-level code during privileged operations. Regular game code should not rely on these objects directly.
- Examples below show how to author a privileged group file — these are examples of files that could live under `/secure/master/security/` and inherit `priviledgeGroup.c`.

Privileged-group example — file manager (inline):
```
inherit "/secure/master/security/priviledgeGroup.c";

protected void applyGroupDetails()
{
    setName("File Manager");
    // Allow read/write across the /areas tree for patching static content
    addPermission("/areas", Read | Write);

    // Allow a restricted set of efuns used by master tools
    addPriviledgedEfun("write_file");
    addPriviledgedEfun("read_file");
    addPriviledgedEfun("mkdir");

    // Permit inheriting objects (wrappers) to use the configured efuns
    allowInheritedPermissions();
}
```

Privileged-group example — execution bridge (inline):
```
inherit "/secure/master/security/priviledgeGroup.c";

protected void applyGroupDetails()
{
    setName("Execution Bridge");
    addPermission("/lib/modules/secure", Read);
    addPriviledgedEfun("exec");
    allowInheritedPermissions();
}
```

Notes:
- The privileged efun whitelist in `priviledgeGroup.c` already constrains which efuns can be added with `addPriviledgedEfun`. Only explicitly allowed efuns can be enabled.
- Privileged groups are for the master and driver checks. Do not attempt to use these objects as substitutes for `/lib/services/groups/*` in-game permission checks.

##### String manipulation
The simulated-efuns provide ANSI-aware, robust string utilities used across the mud.

- `format(string data, int length = 78)`  
  - Wraps and preserves ANSI color codes; it uses `formatColoredString` internally when it detects color escape sequences.
  - Example (inline):
    ```
    string wrapped = format("\x1b[0;36mLong colored description...\x1b[0m", 60);
    ```

- `textWidth`, `unicodeIsSingleCharacter`  
  - Helpers to measure display width considering Unicode/driver capability and stripping ANSI sequences when necessary.

- `regreplace`, `lower_case`, `upper_case`, `capitalizeAllWords`  
  - Thin validated wrappers around efuns.

- `convertDataToString(mixed data)`  
  - Debug-friendly object/array/mapping-to-string converter.

- `stringFromList(string *list, int isOr)` — human readable join of lists (`a, b, and c` or `a or b`).

- `process_string` intentionally disabled in this codebase (returns `"Disabled\n"`).

##### Users
Simulated-efuns expose safe helpers and test-mode hooks for user and interactive handling.

- Registration and lookups
  - `addUser(object user)` — registers interactive players/wizards to internal `players`/`wizards` mappings (caller must be interactive or in secure namespaces).
  - `addLiving(object creature)` — registers non-player livings and prunes stale entries later.
  - `findPlayer(string name)`, `findLiving(string name)`, `users()`, `players()`, `wizards()` — lookup helpers. `users()` filters `efun::users()` by visibility (honors `isInvisibleToCaller` if implemented).

- Interactive helpers
  - `query_ip_name`, `query_ip_number`, `query_idle` — wrappers that return connection info if the object is interactive.
  - `configureCharset(object player, string charset)` — sets the interactive encoding for the player (`"unicode"` ⇒ UTF-8).

- Good practices
  - Don’t rely on `efun::users()` directly in libraries that need to be testable — use `users()` wrapper so tests can substitute canned lists.

##### Databases (important: internal-only)
Database helpers in `secure/simulated-efuns/database.c` are low-level and intended for core/migration code only. Application authors should not call driver-level DB efuns directly.

- NEVER call driver-level DB helpers directly in gameplay code. Specifically, avoid calling:
  - `db_connect`, `db_handles`, `db_exec`, `db_fetch`, `db_error`, etc. — these are internal and may be wrapped or validated by the persistence layer.
- Use the provided data-access services:
  - `/lib/modules/secure/dataAccess.c` (and other higher-level services) expose safe, audited, schema-aware methods that hide SQL and connection details.
  - Example pattern (inline): instead of `db_connect` do:
    ```
    object data = load_object("/lib/modules/secure/dataAccess.c");
    data->savePlayer(playerObj);   // hypothetical service method
    ```

- What the simulated-efuns DB code does
  - `db_connect` wrapper will run `validateDatabase` on the first connection, which calls migration scripts and initial SQL from `/secure/simulated-efuns/database/`.
  - `validateDatabase` & `migrateDatabase` ensure schema is created and up-to-date; migration SQL files live under `/secure/simulated-efuns/database/migrations/`.
  - `db_exec` in the simulated-efuns wraps efun `db_exec` and logs driver errors to `/log/DBERROR`.
  - `db_handles()` is deliberately disabled (returns `({})`) for security — do not expect to enumerate handles.

- Testing and CI
  - `testing.c` includes `validateTestDatabase()` to create/migrate a test DB for CI runs. Tests should call service-layer helpers, not db_ efuns.

##### Short recommended rules
- Use `getService("...")` to get services. Avoid `load_object(...)` unless you truly need to.
- For permission checks in gameplay: use `/lib/services/groups/*` objects and their APIs.
- Do not call database efuns directly — use the secure data-access services.
- Use `users()`, `findPlayer()`, and other simulated-efun wrappers for testable user interactions.
- When authoring text output, prefer `format()` and `textWidth()` to handle ANSI/unicode reliably.

References
- Group templates: `/lib/services/groups/*` (see `baseGroup.c`).
- Master-level privileged definitions: `/secure/master/security/*` (`priviledgeGroup.c`, `priviledgedObjects.c`).
- DB migration scripts and SQL templates: `/secure/simulated-efuns/database/`.
- Test harness: `/secure/simulated-efuns/testing.c` (short-circuit `call_out`, canned users).

This file collects the patterns and policies you should follow when using the simulated efuns: prefer service layers, use group objects for authorization, avoid direct DB calls from gameplay code, and use the wrappers for reliable, testable behavior.
