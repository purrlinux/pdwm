pkgname=pdwm
pkgver=1.0
pkgrel=22
pkgdesc="Minimalist dynamic window manager setup"
arch=('x86_64')
url="https://github.com/purrlinux/pdwm"
license=('MIT')
depends=('xorg-server' 'xorg-xrandr' 'xorg-xsetroot' 'xorg-xinit' 'feh' 'adobe-source-code-pro-fonts')
makedepends=('git' 'gcc')
source=("git+https://github.com/purrlinux/pdwm.git")
sha256sums=('SKIP')
install=pdwm.install

build() {
    cd pdwm

    for dir in dmenu-5.3 dwm-6.5 slock-1.5 slstatus-1.0 st-0.9.2; do
        cd "$dir"
        make
        cd ..
    done
}

package() {
    cd pdwm

    install -Dm755 dwm-6.5/dwm "$pkgdir/usr/bin/dwm"
    install -Dm755 dmenu-5.3/dmenu_path "$pkgdir/usr/bin/dmenu_path"
    install -Dm755 dmenu-5.3/dmenu_run "$pkgdir/usr/bin/dmenu_run"
    install -Dm755 dmenu-5.3/dmenu "$pkgdir/usr/bin/dmenu"
    install -Dm755 dmenu-5.3/stest "$pkgdir/usr/bin/stest"
    install -Dm755 slock-1.5/slock "$pkgdir/usr/bin/slock"
    install -Dm755 slstatus-1.0/slstatus "$pkgdir/usr/bin/slstatus"
    install -Dm755 st-0.9.2/st "$pkgdir/usr/bin/st"

    install -Dm644 dwm-6.5/autostart.sh "$pkgdir/usr/share/pdwm/skel/.dwm/autostart.sh"
    install -Dm644 wallpaper.png "$pkgdir/usr/share/pdwm/wallpaper.png"

    install -Dm644 dwm-6.5/dwm.1 "$pkgdir/usr/share/man/man1/dwm.1"
    install -Dm644 dmenu-5.3/dmenu.1 "$pkgdir/usr/share/man/man1/dmenu.1"
    install -Dm644 slock-1.5/slock.1 "$pkgdir/usr/share/man/man1/slock.1"
    install -Dm644 slstatus-1.0/slstatus.1 "$pkgdir/usr/share/man/man1/slstatus.1"
    install -Dm644 st-0.9.2/st.1 "$pkgdir/usr/share/man/man1/st.1"

    install -Dm644 <(echo "[Desktop Entry]
Name=DWM
Comment=Dynamic Window Manager
Exec=dwm
Type=Application
X-LightDM-Session=true") "$pkgdir/usr/share/xsessions/dwm.desktop"

    chmod u+s "$pkgdir/usr/bin/slock"
}