{
  inputs = {
    # self needs to be passed in as `nix build '.?submodules=1'`.
    nixpkgs.url = "github:NixOS/nixpkgs/22.11";
    flake-utils.url  = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils, ... }:
    flake-utils.lib.eachDefaultSystem (system: let pkgs = nixpkgs.legacyPackages.${system}; in rec {
    packages.default = with pkgs.pkgsCross.arm-embedded; stdenv.mkDerivation {
      src = self;
      preBuild = "cd movement/make";
      name = "sensor-watch";
      nativeBuildInputs = [ buildPackages.python3 ];
      installPhase = ''
        mkdir -p $out
        cp build/watch.uf2 $out
      '';
    };
    devShells.default = packages.default;
  });
}
