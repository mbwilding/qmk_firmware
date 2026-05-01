{
  description = "QMK Firmware development environment";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs =
    {
      self,
      nixpkgs,
      flake-utils,
    }:
    flake-utils.lib.eachDefaultSystem (
      system:
      let
        pkgs = nixpkgs.legacyPackages.${system};
        python = pkgs.python3.withPackages (
          ps: with ps; [
            argcomplete
            colorama
            dotty-dict
            hid
            hjson
            jsonschema
            milc
            pygments
            pyserial
            pyusb
            pillow
          ]
        );
      in
      let
        keyboard = "zsa/voyager";
        keymap = "mbwilding";

        deps = with pkgs; [
          gcc-arm-embedded
          pkgsCross.avr.buildPackages.gcc
          avrdude
          gnumake
          git
          python
          qmk
          dfu-util
          dfu-programmer
        ];
      in
      {
        devShells.default = pkgs.mkShell {
          packages = deps;
          shellHook = ''
            export QMK_HOME="$(pwd)"
          '';
        };

        apps.build = {
          type = "app";
          program = toString (
            pkgs.writeShellScript "qmk-build" ''
              export PATH="${pkgs.lib.makeBinPath deps}:$PATH"
              export QMK_HOME="$(pwd)"
              exec ${pkgs.gnumake}/bin/make ${keyboard}:${keymap}
            ''
          );
        };

        apps.flash = {
          type = "app";
          program = toString (
            pkgs.writeShellScript "qmk-flash" ''
              export PATH="${pkgs.lib.makeBinPath deps}:$PATH"
              export QMK_HOME="$(pwd)"
              exec ${pkgs.gnumake}/bin/make ${keyboard}:${keymap}:flash
            ''
          );
        };

        apps.default = self.apps.${system}.build;
      }
    );
}
