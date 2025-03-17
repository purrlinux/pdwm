pkgname=pdwm
pkgver=1.0
pkgrel=25
pkgdesc="Minimalist dynamic window manager setup"
arch=('x86_64')
url="https://github.com/purrlinux/pdwm"
license=('MIT')
depends=('xorg-server' 'xorg-xrandr' 'xorg-xsetroot' 'xorg-xinit' 'feh' 'adobe-source-code-pro-fonts')
makedepends=('git' 'gcc' 'make')
source=("git+https://github.com/purrlinux/pdwm.git")
sha256sums=('SKIP')
install=pdwm.install

build() {
    cd pdwm
    for dir in dmenu-5.3 dwm-6.5 slock-1.5 slstatus-1.0 st-0.9.2; do
        make -C "$dir"
    done
}

package() {
    cd pdwm

    install -Dm755 dwm-6.5/dwm dmenu-5.3/dmenu_path dmenu-5.3/dmenu_run \
        dmenu-5.3/dmenu dmenu-5.3/stest slstatus-1.0/slstatus st-0.9.2/st \
        -t "$pkgdir/usr/bin/"

    install -Dm4755 slock-1.5/slock "$pkgdir/usr/bin/slock"

    install -Dm644 dwm-6.5/autostart.sh "$pkgdir/usr/share/pdwm/skel/.dwm/autostart.sh"
    install -Dm644 wallpaper.png "$pkgdir/usr/share/pdwm/wallpaper.png"

    install -Dm644 dwm-6.5/dwm.1 dmenu-5.3/dmenu.1 slock-1.5/slock.1 \
        slstatus-1.0/slstatus.1 st-0.9.2/st.1 -t "$pkgdir/usr/share/man/man1/"

    install -Dm644 <(echo "[Desktop Entry]
Name=DWM
Comment=Dynamic Window Manager
Exec=dwm
Type=Application
X-LightDM-Session=true") "$pkgdir/usr/share/xsessions/dwm.desktop"
}
