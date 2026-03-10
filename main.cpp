#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

constexpr int TILE=20;

struct World{
    std::vector<std::vector<int>> world={
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,1,0,1,1,1,0,1},
        {1,0,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,1,0,1,1,1,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,1,1,0,0,0,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,0,0,0,1,1,0,1},
        {1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,0,1,0,0,1,1,1,1,1,1,0,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,0,1,0,0,1,1,1,1,0,0,0,1,1,1,1,0,0,1,0,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,0,1,1,1,1,1,1},
        {0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
        {1,1,1,1,1,1,1,0,1,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,1,0,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,0,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,0,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1},
        {1,0,0,0,0,1,0,0,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,0,0,1,0,0,0,0,1},
        {1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1},
        {1,1,1,1,0,1,0,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,0,1,0,1,1,1,1},
        {1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
        {1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,0,0,0,1,1,1,1,1,1,1,1,1,1,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };

    int row=world.size();
    int col=world[0].size(); 

    void draw(sf::RenderWindow& window){
        sf::RectangleShape wall(sf::Vector2f(TILE-1, TILE-1)); 
        sf::CircleShape food(float(TILE-18));
        sf::CircleShape pacman(float(TILE-10));

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(world[i][j]==1){
                    wall.setFillColor(sf::Color::Blue);
                    wall.setPosition({float(j*TILE), float(i*TILE)});
                    window.draw(wall);
                }
                if(world[i][j]==2){
                    food.setFillColor(sf::Color::Yellow);
                    food.setPosition({float(j*TILE), float(i*TILE)});
                    window.draw(food);
                } 
            }
        }
    }
};

struct User{ //3 serà su identidad
    int x=10, y=15; //posicion antigua que servirà para el frame suave
    int nx, ny;
    sf::CircleShape user;

    enum Dir{ LEFT, DOWN, RIGHT, UP};
    Dir dir=RIGHT;

    User(){
        user.setRadius(float(TILE-10));
        user.setPosition(sf::Vector2f(TILE*10, TILE*10));
        user.setFillColor(sf::Color::Yellow);
    }

    void init(World& w){
        w.world[x][y]=3;
    }

    void handleInput(World& w){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) dir=LEFT;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) dir=RIGHT;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) dir=UP;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) dir=DOWN;
    }

    void update(World& w){
        int dx=0, dy=0;
        
        if(dir==LEFT) dy=-1;
        if(dir==RIGHT) dy=1;
        if(dir==UP) dx=-1;
        if(dir==DOWN) dx=1;

        nx=x+dx;
        ny=y+dy;

        //OBSTACULOS
        if(nx<=0 || nx>=w.row-1 || ny<=0 || ny>=w.col-1 ||
           w.world[nx][ny]==1) return;
        //if()

        w.world[x][y]=0;
        w.world[nx][ny]=3; //IDENTIDAD DEL USUARIO 3 

        //AQUI ACTUALIZAMOS
        x=nx;
        y=ny;
    }

    void draw(sf::RenderWindow& window, float& alpha){
        float newX=x + (nx-x) * alpha;
        float newY=y + (ny-y) * alpha;

        user.setPosition(sf::Vector2f(newY*TILE, newX*TILE));
        window.draw(user);
    }
};

struct Food{
    //recordar regla de oro:
    //si pacman come, lugar se pone en 0, es decir, lugar vacio
    void init(World& _w){
        for(int i=0; i<_w.row; i++){
            for(int j=0; j<_w.col; j++){
                if(_w.world[i][j]==0) _w.world[i][j]=2;
            }
        }
    }
};

void execute(){
    World _w;
    Food _f;
    User _u;

    sf::RenderWindow window{
        sf::VideoMode({
                static_cast<unsigned>(_w.row*TILE),
                static_cast<unsigned>(_w.col*TILE)
        }),
        "PACMAN :v but no mmiss pacman :3"
    };

    window.setFramerateLimit(60);

    _f.init(_w);
    _u.init(_w);

    sf::Clock clock;
    float timer=0;
    float delay=0.07;

    while(window.isOpen()){
        while(const std::optional event=window.pollEvent()){
            if(event->is<sf::Event::Closed>()) window.close(); 
        }

        _u.handleInput(_w);
        float t=clock.restart().asSeconds();
        timer+=t;

        if(timer>delay){
            _u.update(_w);
            timer-=delay;
        }
        float alpha=timer/delay;

        window.clear();
        _w.draw(window);
        _u.draw(window, alpha);
        window.display();
    }
}

int main(){
    execute();
    return 0;
}

//g++ -o m main.cpp -lsfml-graphics -lsfml-window -lsfml-system
